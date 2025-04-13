#include <fstream>
#include <vector>
#include <iostream>
#include "radix_sort.hpp"

using namespace std;

// Funkcija za branje števil iz datoteke in shranjevanje v vektor
bool Branje_Stevil(vector<unsigned char> &stevila, const char imeDatoteke[]) {
    ifstream vhodnaDatoteka(imeDatoteke);
    int stevilo;

    if (!vhodnaDatoteka.is_open()) {
        return false;
    }

    while (vhodnaDatoteka >> stevilo) {
        if (stevilo >= 0 && stevilo <= 255) {
            stevila.push_back(static_cast<unsigned char>(stevilo));
        }
    }

    vhodnaDatoteka.close();
    return true;
}

// Funkcija za izpis števil v izhodno datoteko
void Izpis_Stevil(const vector<unsigned char> &stevila) {
    ofstream izhodnaDatoteka("out.txt");

    for (size_t i = 0; i < stevila.size(); i++) {
        int stevilo = static_cast<int>(stevila[i]);
        izhodnaDatoteka << stevilo << ' ';
    }
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Ni podan vhodni argument (ime datoteke)." << endl;
        return 1;
    }

    vector<unsigned char> stevila;
    if (!Branje_Stevil(stevila, argv[1])) {
        cerr << "Napaka pri branju datoteke." << endl;
        return 1;
    }

    Binary_Radix_Sort(stevila);
    Izpis_Stevil(stevila);

    return 0;
}
