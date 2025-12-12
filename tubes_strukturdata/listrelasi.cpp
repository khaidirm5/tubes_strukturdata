//
//  listrelasi.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "listrelasi.h"
#include <iostream>

void createListRelasi(ListRelasi &L) {
    L.first = nullptr;
}

void insertRelasi(ListRelasi &L, addressRelasi R) {
    R->next = L.first;
    L.first = R;
}

void deleteRelasiToko(ListRelasi &L, addressToko T) {
    addressRelasi P = L.first, prev = nullptr;

    while (P != nullptr) {
        if (P->toko == T) {
            if (prev == nullptr)
                L.first = P->next;
            else
                prev->next = P->next;

            delete P;
            return;
        }
        prev = P;
        P = P->next;
    }
}

void deleteRelasiBarang(ListRelasi &L, addressBarang B) {
    addressRelasi P = L.first, prev = nullptr;

    while (P != nullptr) {
        if (P->barang == B) {
            if (prev == nullptr)
                L.first = P->next;
            else
                prev->next = P->next;

            delete P;
            return;
        }
        prev = P;
        P = P->next;
    }
}

void printRelasi(ListRelasi L) {
    addressRelasi P = L.first;
    while (P != nullptr) {
        std::cout << P->toko->info.namaToko
                  << " menjual "
                  << P->barang->info.namaBarang << "\n";
        P = P->next;
    }
}
    