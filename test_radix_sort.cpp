#include <cassert>
#include <vector>
#include "radix_sort.hpp"
#include <iostream>
using namespace std;

// Deklaracija funkcije iz main.cpp
void Binary_Radix_Sort(vector<unsigned char> &stevila);

// Pomozna funkcija za primerjavo vektorjev
bool enakaVektorja(const vector<unsigned char>& a, const vector<unsigned char>& b) {
    return a == b;
}

int main() {
    {
        vector<unsigned char> test1 = {5, 3, 9, 1};
        vector<unsigned char> expected1 = {1, 3, 5, 9};
        Binary_Radix_Sort(test1);
        assert(enakaVektorja(test1, expected1));
    }

    {
        vector<unsigned char> test2 = {255, 0, 127};
        vector<unsigned char> expected2 = {0, 127, 255};
        Binary_Radix_Sort(test2);
        assert(enakaVektorja(test2, expected2));
    }

    {
        vector<unsigned char> test3 = {};
        vector<unsigned char> expected3 = {};
        Binary_Radix_Sort(test3);
        assert(enakaVektorja(test3, expected3));
    }

    cout << "Vsi testi so uspešno prestani!" << endl;
    return 0;
}
