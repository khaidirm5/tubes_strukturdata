//
//  listtoko.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "listtoko.h"
#include <iostream>

void createListToko(ListToko &L) {
    L.first = nullptr;
    L.count = 0;
}

addressToko buatElmToko(infotypeToko x) {
    addressToko P = new elmToko;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertToko(ListToko &L, addressToko P) {
    P->next = L.first;
    L.first = P;
    L.count++;
}

addressToko findToko(ListToko L, string id) {
    addressToko P = L.first;
    while (P) {
        if (P->info.idToko == id) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteToko(ListToko &L, string id) {
    addressToko P = L.first, prev = nullptr;
    while (P) {
        if (P->info.idToko == id) {
            if (!prev) L.first = P->next;
            else prev->next = P->next;
            delete P;
            L.count--;
            return;
        }
        prev = P;
        P = P->next;
    }
}

void inputToko(infotypeToko &x) {
    cout << "ID Toko   : ";
    getline(cin, x.idToko);
    cout << "Nama Toko : ";
    getline(cin, x.namaToko);
}
