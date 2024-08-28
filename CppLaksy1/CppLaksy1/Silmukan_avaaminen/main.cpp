#include <iostream>
#include <ctime>

#define WIDTH 40
#define HEIGHT 25
#define SIZE (WIDTH * HEIGHT)

void scroll_up(char *screen) {
    for (int i = 0; i < SIZE - WIDTH; i++) {
        screen[i] = screen[i + WIDTH];
    }
    for (int i = SIZE - WIDTH; i < SIZE; i++) {
        screen[i] = ' ';
    }
}

int main() {
    clock_t alku, loppu;
    double suoritusaika;
    char screen[SIZE];

    // Alustetaan näyttö joillakin tiedoilla
    for (int i = 0; i < SIZE; i++) {
        screen[i] = 'A' + (i % 26);
    }

    alku = clock();
    for (int i = 0; i < 1000; i++) {
        scroll_up(screen);
    }
    loppu = clock();

    suoritusaika = static_cast<double>(loppu - alku) / CLOCKS_PER_SEC;
    std::cout << "Aikaa kului: " << suoritusaika << " sekuntia" << std::endl;

    return 0;
}