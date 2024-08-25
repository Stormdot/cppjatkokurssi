#include "2_Tililtanostaminen.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

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

void tililtaNostaminenMain() {
    PankkiTili tili;
    const int siirrot = 100;
    const int maara = 1;

    thread t1(teeTalletus, ref(tili), maara, siirrot);
    thread t2(teeNosto, ref(tili), maara, siirrot);

    t1.join();
    t2.join();

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