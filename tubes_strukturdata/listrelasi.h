//
//  listrelasi.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTRELASI_H
#define LISTRELASI_H

#include "relasi.h"

struct ListRelasi {
    addressRelasi first;
};

void createListRelasi(ListRelasi &L);
void insertRelasi(ListRelasi &L, addressRelasi R);

/* DIPERBAIKI */
void deleteAllRelasiToko(ListRelasi &L, addressToko T);
void deleteAllRelasiBarang(ListRelasi &L, addressBarang B);

void printRelasi(ListRelasi L);

#endif
