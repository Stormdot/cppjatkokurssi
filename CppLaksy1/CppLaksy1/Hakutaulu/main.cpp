#include <iostream>
#include <cmath>
#include <ctime>

#define ITERATIONS 1000000

int main() {
    clock_t alku, loppu;
    double suoritusaika;
    double tulos = 0.0;

    alku = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        tulos += sin(i);
    }
    loppu = clock();

    suoritusaika = static_cast<double>(loppu - alku) / CLOCKS_PER_SEC;
    std::cout << "Tulos: " << tulos << std::endl;
    std::cout << "Aikaa kului: " << suoritusaika << " sekuntia" << std::endl;

    return 0;
}