#pragma once
#include <mutex>

class PankkiTili {
public:
    PankkiTili() : saldo(0), talletus_count(0), nosto_count(0) {}

    void tallenna(int maara) {
        std::lock_guard<std::mutex> guard(tili_mutex);
        saldo += maara;
        talletus_count++;
    }

    void nosta(int maara) {
        std::lock_guard<std::mutex> guard(tili_mutex);
        if (saldo >= maara) {
            saldo -= maara;
            nosto_count++;
        }
    }

    int haeSaldo() const {
        std::lock_guard<std::mutex> guard(tili_mutex);
        return saldo;
    }

    int getTalletusCount() const {
        std::lock_guard<std::mutex> guard(tili_mutex);
        return talletus_count;
    }

    int getNostoCount() const {
        std::lock_guard<std::mutex> guard(tili_mutex);
        return nosto_count;
    }

    void resetSaldo() {
        std::lock_guard<std::mutex> guard(tili_mutex);
        saldo = 0;
    }

private:
    int saldo;
    int talletus_count;
    int nosto_count;
    mutable std::mutex tili_mutex;
};