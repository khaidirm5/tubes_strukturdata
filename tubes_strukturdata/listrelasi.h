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
void deleteRelasiToko(ListRelasi &L, addressToko T);
void deleteRelasiBarang(ListRelasi &L, addressBarang B);
void printRelasi(ListRelasi L);

// BAGIAN LIA BARU
void tampilSemuaTokoBesertaBarang(ListToko LT, ListRelasi LR);
void tampilBarangDariToko(ListToko LT, ListRelasi LR, std::string idToko);
void tampilTokoDariBarang(ListBarang LB, ListRelasi LR, std::string idBarang);
void tokoPalingLengkapDanSedikit(ListToko LT, ListRelasi LR);        

#endif
