#include <iostream>
#include <vector>
#include <numeric>
#include <future>
#include <mutex>
using namespace std;

const size_t koko = 10000000;
const int saikeidenMaara = 4;
vector<size_t> taulukko(koko);
mutex lukko;

long long laskeSumma(size_t aloitusIndeksi, size_t lopetusIndeksi) {
    long long localSum = accumulate(taulukko.begin() + aloitusIndeksi, taulukko.begin() + lopetusIndeksi, 0LL);
    lock_guard<mutex> guard(lukko);
    cout << "Thread: " << this_thread::get_id() << " laskee summan indekseilla " << aloitusIndeksi << " - " << lopetusIndeksi << "\n Summa on: " << localSum << endl;
    return localSum;
}

void main() {
    iota(taulukko.begin(), taulukko.end(), 1);
    vector<future<long long>> futures;

    size_t osanKoko = koko / saikeidenMaara;
    for (int i = 0; i < saikeidenMaara; ++i) {
        size_t aloitusIndeksi = i * osanKoko;
        size_t lopetusIndeksi = (i == saikeidenMaara - 1) ? koko : aloitusIndeksi + osanKoko;
        futures.push_back(async(laskeSumma, aloitusIndeksi, lopetusIndeksi));
    }

    long long kokonaissumma = 0;
    for (auto& fut : futures) {
        kokonaissumma += fut.get();
    }

    cout << "Kokonaissumma: " << kokonaissumma << endl;
}