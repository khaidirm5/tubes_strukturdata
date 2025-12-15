//
//  listbarang.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "listbarang.h"

void createListBarang(ListBarang &L) {
    L.first = nullptr;
}

addressBarang buatElmBarang(infotypeBarang x) {
    addressBarang P = new ElmBarang;
    P->info = x;
    P->next = nullptr;
    return P;
}

// INSERT LAST (WAJIB beda)
void insertBarang(ListBarang &L, addressBarang P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        addressBarang Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

addressBarang findBarang(ListBarang L, std::string id) {
    addressBarang P = L.first;
    while (P != nullptr && P->info.idBarang != id) {
        P = P->next;
    }
    return P;
}

void deleteBarang(ListBarang &L, std::string id) {
    addressBarang P = L.first, prev = nullptr;

    while (P != nullptr && P->info.idBarang != id) {
        prev = P;
        P = P->next;
    }

    if (P == nullptr) return;

    if (prev == nullptr)
        L.first = P->next;
    else
        prev->next = P->next;

    delete P;
}
