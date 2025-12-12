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
}

addressToko buatElmToko(infotypeToko x) {
    addressToko P = new ElmToko;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertToko(ListToko &L, addressToko P) {
    P->next = L.first;
    L.first = P;
}

addressToko findToko(ListToko L, std::string id) {
    addressToko P = L.first;
    while (P != nullptr && P->info.idToko != id) {
        P = P->next;
    }
    return P;
}

void deleteToko(ListToko &L, std::string id) {
    addressToko P = L.first;
    addressToko prev = nullptr;

    while (P != nullptr && P->info.idToko != id) {
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
