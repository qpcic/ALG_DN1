// radix_sort.cpp
#include "radix_sort.hpp"
#include <vector>

void Binary_Radix_Sort(std::vector<unsigned char>& stevila) {
    size_t dolzina = stevila.size();
    std::vector<int> urejeniIndeksi(dolzina);
    for (size_t i = 0; i < dolzina; i++) {
        urejeniIndeksi[i] = i;
    }

    for (int k = 0; k < 8; k++) {
        std::vector<int> stevec(2, 0);
        for (size_t i = 0; i < dolzina; i++) {
            int bitnaVrednost = (stevila[urejeniIndeksi[i]] >> k) & 1;
            stevec[bitnaVrednost]++;
        }
        stevec[1] += stevec[0];
        std::vector<int> noviUrejeniIndeksi(dolzina);
        for (int i = dolzina - 1; i >= 0; i--) {
            int bitnaVrednost = (stevila[urejeniIndeksi[i]] >> k) & 1;
            stevec[bitnaVrednost]--;
            noviUrejeniIndeksi[stevec[bitnaVrednost]] = urejeniIndeksi[i];
        }
        urejeniIndeksi = noviUrejeniIndeksi;
    }

    std::vector<unsigned char> urejenaStevila(dolzina);
    for (size_t i = 0; i < dolzina; i++) {
        urejenaStevila[i] = stevila[urejeniIndeksi[i]];
    }
    stevila = urejenaStevila;
}