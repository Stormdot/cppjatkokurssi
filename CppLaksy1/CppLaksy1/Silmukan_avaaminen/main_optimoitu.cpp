#include <iostream>
#include <ctime>
#include <vector>

#define WIDTH 40
#define HEIGHT 25
#define SIZE (WIDTH * HEIGHT)

void scroll_up(char *screen, char *buffer) {
    for (int i = 0; i < SIZE - WIDTH; i++) {
        buffer[i] = screen[i + WIDTH];
    }
    for (int i = SIZE - WIDTH; i < SIZE; i++) {
        buffer[i] = ' ';
    }
    for (int i = 0; i < SIZE; i++) {
        screen[i] = buffer[i];
    }
}

int main() {
    clock_t alku, loppu;
    double suoritusaika;
    char screen[SIZE];
    char *buffer = (char *)malloc(SIZE * sizeof(char));

    // Alustetaan näyttö joillakin tiedoilla
    for (int i = 0; i < SIZE; i++) {
        screen[i] = 'A' + (i % 26);
    }

    alku = clock();
    for (int i = 0; i < 1000; i++) {
        scroll_up(screen, buffer);
    }
    loppu = clock();

    suoritusaika = static_cast<double>(loppu - alku) / CLOCKS_PER_SEC;
    std::cout << "Aikaa kului: " << suoritusaika << " sekuntia" << std::endl;

    free(buffer);
    return 0;
}