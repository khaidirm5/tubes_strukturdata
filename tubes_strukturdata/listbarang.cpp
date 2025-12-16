//
//  listbarang.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "listbarang.h"
#include "listrelasi.h"
#include <iostream>

void createListBarang(ListBarang &L) {
    L.first = nullptr;
}

addressBarang buatElmBarang(infotypeBarang x) {
    addressBarang P = new elmBarang;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertBarang(ListBarang &L, addressBarang P) {
    P->next = L.first;
    L.first = P;
}

addressBarang findBarang(ListBarang L, string id) {
    addressBarang P = L.first;
    while (P) {
        if (P->info.idBarang == id) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteBarang(ListBarang &L, string id) {
    addressBarang P = L.first, prev = nullptr;
    while (P) {
        if (P->info.idBarang == id) {
            if (!prev) L.first = P->next;
            else prev->next = P->next;
            delete P;
            return;
        }
        prev = P;
        P = P->next;
    }
}

void deleteBarangTanpaRelasi(ListBarang &LB, ListRelasi LR) {
    addressBarang B = LB.first;
    while (B) {
        bool ada = false;
        addressRelasi R = LR.first;
        while (R) {
            if (R->barang == B) {
                ada = true;
                break;
            }
            R = R->next;
        }
        addressBarang nextB = B->next;
        if (!ada) deleteBarang(LB, B->info.idBarang);
        B = nextB;
    }
}

void inputBarang(infotypeBarang &x) {
    cout << "ID Barang   : ";
    getline(cin, x.idBarang);
    cout << "Nama Barang : ";
    getline(cin, x.namaBarang);
    cout << "Harga       : ";
    cin >> x.harga;
    cin.ignore();
}

