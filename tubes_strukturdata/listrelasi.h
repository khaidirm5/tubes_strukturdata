//
//  listrelasi.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTRELASI_H
#define LISTRELASI_H

#include "relasi.h"
#include "listtoko.h"
#include "listbarang.h"

struct ListRelasi {
    addressRelasi first;
};

void createListRelasi(ListRelasi &L);
void insertRelasi(ListRelasi &L, addressRelasi R);
void printRelasi(ListRelasi L);

void deleteAllRelasiToko(ListRelasi &L, addressToko T);
void deleteAllRelasiBarang(ListRelasi &L, addressBarang B);

void printBarangByToko(ListRelasi LR, addressToko T);
void printTokoByBarang(ListRelasi LR, addressBarang B);
void cariTokoEkstrem(ListToko LT, ListRelasi LR);

#endif
