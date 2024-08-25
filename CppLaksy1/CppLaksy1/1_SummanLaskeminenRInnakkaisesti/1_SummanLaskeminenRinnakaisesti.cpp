#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <mutex>
using namespace std;

const size_t koko = 10000000;
const int saikeidenMaara = 4;
vector<size_t> taulukko(koko);
mutex lukko;

void laskeSumma(size_t aloitusIndeksi, size_t lopetusIndeksi, long long* summa) {
    long long localSum = accumulate(taulukko.begin() + aloitusIndeksi, taulukko.begin() + lopetusIndeksi, 0LL);
    lock_guard<mutex> guard(lukko);
    *summa = localSum;
    cout << "Thread: " << this_thread::get_id() << " laskee summan indekseilla " << aloitusIndeksi << " - " << lopetusIndeksi << "\n Summa on: " << *summa << endl;
}

int main() {
    iota(taulukko.begin(), taulukko.end(), 1);
    vector<thread> saikeet;
    vector<long long> summat(saikeidenMaara, 0);

    size_t osanKoko = koko / saikeidenMaara;
    for (int i = 0; i < saikeidenMaara; ++i) {
        size_t aloitusIndeksi = i * osanKoko;
        size_t lopetusIndeksi = (i == saikeidenMaara - 1) ? koko : aloitusIndeksi + osanKoko;
        saikeet.push_back(thread(laskeSumma, aloitusIndeksi, lopetusIndeksi, &summat[i]));
    }

    for (auto& saie : saikeet) {
        saie.join();
    }

    long long kokonaissumma = accumulate(summat.begin(), summat.end(), 0LL);

    cout << "Kokonaissumma: " << kokonaissumma << endl;

    return 0;
}