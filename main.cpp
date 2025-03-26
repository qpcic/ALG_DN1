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
