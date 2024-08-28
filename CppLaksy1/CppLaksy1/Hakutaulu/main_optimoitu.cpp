#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

#define ITERATIONS 1000000

int main() {
    clock_t alku, loppu;
    double suoritusaika;
    double tulos = 0.0;
    std::vector<double> sin_arvot(ITERATIONS);

    // Esilasketaan sini-arvot
    for (int i = 0; i < ITERATIONS; i++) {
        sin_arvot[i] = sin(i);
    }

    alku = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        tulos += sin_arvot[i];
    }
    loppu = clock();

    suoritusaika = static_cast<double>(loppu - alku) / CLOCKS_PER_SEC;
    std::cout << "Tulos: " << tulos << std::endl;
    std::cout << "Aikaa kului: " << suoritusaika << " sekuntia" << std::endl;

    return 0;
}