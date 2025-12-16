//
//  listbarang.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTBARANG_H
#define LISTBARANG_H

#include <string>
using namespace std;

struct infotypeBarang {
    string idBarang;
    string namaBarang;
    int harga;
};

typedef struct elmBarang *addressBarang;

struct elmBarang {
    infotypeBarang info;
    addressBarang next;
};

struct ListBarang {
    addressBarang first;
};

void createListBarang(ListBarang &L);
addressBarang buatElmBarang(infotypeBarang x);
void insertBarang(ListBarang &L, addressBarang P);
addressBarang findBarang(ListBarang L, string id);
void deleteBarang(ListBarang &L, string id);
void deleteBarangTanpaRelasi(ListBarang &LB, struct ListRelasi LR);
void inputBarang(infotypeBarang &x);

#endif

