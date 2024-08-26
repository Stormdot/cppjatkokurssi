#include "2_Tililtanostaminen.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <future>
#include <mutex>

using namespace std;

void teeTalletus(PankkiTili& tili, int maara, int toistot) {
    for (int i = 0; i < toistot; i++) {
        tili.tallenna(maara);
    }
}

void teeNosto(PankkiTili& tili, int maara, int toistot) {
    for (int i = 0; i < toistot; i++) {
        tili.nosta(maara);
    }
}

void main() {
    PankkiTili tili;
    const int siirrot = 1000;
    const int maara = 1;

    auto future1 = async(teeTalletus, ref(tili), maara, siirrot);
    auto future2 = async(teeNosto, ref(tili), maara, siirrot);

    future1.get();
    future2.get();

    cout << "Lopullinen saldo: " << tili.haeSaldo() << endl;
    cout << "Talletuksia: " << tili.getTalletusCount() << endl;
    cout << "Nostoja: " << tili.getNostoCount() << endl;

    if (tili.haeSaldo() > 0) {
        cout << "Soitetaan asiakaspalveluun" << endl;
        cout << "Odotetaan 3 pankkipäivää" << endl;
        tili.resetSaldo();
        cout << "Saldo on nyt " << tili.haeSaldo() << endl;
    }
}
