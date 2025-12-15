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

/* HAPUS SEMUA RELASI TOKO */
void deleteAllRelasiToko(ListRelasi &L, addressToko T) {
    addressRelasi P = L.first;
    addressRelasi prev = nullptr;

    while (P != nullptr) {
        if (P->toko == T) {
            addressRelasi temp = P;

            if (prev == nullptr) {
                L.first = P->next;
                P = L.first;
            } else {
                prev->next = P->next;
                P = P->next;
            }

            delete temp;
        } else {
            prev = P;
            P = P->next;
        }
    }
}

/* HAPUS SEMUA RELASI BARANG */
void deleteAllRelasiBarang(ListRelasi &L, addressBarang B) {
    addressRelasi P = L.first;
    addressRelasi prev = nullptr;

    while (P != nullptr) {
        if (P->barang == B) {
            addressRelasi temp = P;

            if (prev == nullptr) {
                L.first = P->next;
                P = L.first;
            } else {
                prev->next = P->next;
                P = P->next;
            }

            delete temp;
        } else {
            prev = P;
            P = P->next;
        }
    }
}

void printRelasi(ListRelasi L) {
    addressRelasi P = L.first;
    while (P != nullptr) {
        std::cout << P->toko->info.namaToko
                  << " menjual "
                  << P->barang->info.namaBarang << std::endl;
        P = P->next;
    }
}
