//
//  listrelasi.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTRELASI_H
#define LISTRELASI_H

#include "listtoko.h"
#include "listbarang.h"

typedef struct elmRelasi *addressRelasi;

struct elmRelasi {
    addressToko toko;
    addressBarang barang;
    addressRelasi next;
};

struct ListRelasi {
    addressRelasi first;
};

void createListRelasi(ListRelasi &L);
addressRelasi buatRelasi(addressToko T, addressBarang B);
void insertRelasi(ListRelasi &L, addressRelasi P);

void deleteAllRelasiToko(ListRelasi &L, addressToko T);
void deleteAllRelasiBarang(ListRelasi &L, addressBarang B);
bool deleteRelasiTokoBarang(ListRelasi &L, addressToko T, addressBarang B);

int hitungBarangToko(ListRelasi L, addressToko T);

void printBarangByToko(ListRelasi L, addressToko T);
void printTokoByBarang(ListRelasi L, addressBarang B);
void cariTokoEkstrem(ListToko LT, ListRelasi LR);
void printTokoByNamaBarang(ListRelasi LR, std::string namaBarang);

#endif




