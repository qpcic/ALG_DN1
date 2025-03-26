#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

// Funkcija za branje stevil iz datoteke in shranjevanje v vektor stevila
bool Branje_Stevil(vector<unsigned char> &stevila, const char imeDatoteke[]) {
    ifstream vhodnaDatoteka(imeDatoteke);
    int stevilo;

    if (!vhodnaDatoteka.is_open()) {
        return false;
    }

    while (vhodnaDatoteka >> stevilo) { // Bere stevila iz datoteke
        if (stevilo >= 0 && stevilo <= 255) { // Preveri, ali je v dovoljenem obsegu
            stevila.push_back(static_cast<unsigned char>(stevilo));
        }
    }
    vhodnaDatoteka.close();
    return true;
}

// Funkcija za zapis urejenih stevil v izhodno datoteko "out.txt"
void Izpis_Stevil(const vector<unsigned char> &stevila) {
    ofstream izhodnaDatoteka("out.txt");

    for (size_t i = 0; i < stevila.size(); i++) {
        int stevilo = static_cast<int>(stevila[i]);
        izhodnaDatoteka << stevilo << ' ';
    }
}

// Funkcija, ki izvede Counting Sort po danem bitu in vrne urejen vrstni red indeksov
void Counting_Sort(const vector<unsigned char> &stevila, vector<int> &urejeniIndeksi, int bitPozicija) {
    size_t dolzina = stevila.size();
    vector<int> stevec(2, 0); // Stevec za bite 0 in 1

    // Prestejemo pojavitve vrednosti bitov (0 in 1)
    for (size_t i = 0; i < dolzina; i++) {
        int bitnaVrednost = (stevila[i] >> bitPozicija) & 1;
        stevec[bitnaVrednost] = stevec[bitnaVrednost] + 1;
    }

    // Ustvarimo kumulativno vsoto za stabilno sortiranje
    stevec[1] = stevec[1] + stevec[0];

    // Vektor za shranjevanje novih urejenih indeksov
    vector<int> noviUrejeniIndeksi(dolzina);

    // Razvrstimo indekse stabilno po bitni vrednosti
    for (int i = dolzina - 1; i >= 0; i--) {
        int bitnaVrednost = (stevila[urejeniIndeksi[i]] >> bitPozicija) & 1;

        stevec[bitnaVrednost] = stevec[bitnaVrednost] - 1;
        int novIndeks = stevec[bitnaVrednost];
        noviUrejeniIndeksi[novIndeks] = urejeniIndeksi[i];
    }

    // Posodobimo urejene indekse
    urejeniIndeksi = noviUrejeniIndeksi;
}

// Glavna funkcija
int main(int argc, const char* argv[]) {
    if (argc < 2) {
        return 1; // Ce ni argumenta, koncamo program
    }

    vector<unsigned char> stevila;
    if (!Branje_Stevil(stevila, argv[1])) {
        return 1; // Ce branje ni uspesno, koncamo program
    }

    Binary_Radix_Sort(stevila);
    Izpis_Stevil(stevila);

    return 0;
}
