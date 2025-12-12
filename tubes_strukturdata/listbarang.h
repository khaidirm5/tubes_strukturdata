//
//  listbarang.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTBARANG_H
#define LISTBARANG_H

#include "barang.h"

struct ListBarang {
    addressBarang first;
};

void createListBarang(ListBarang &L);
addressBarang buatElmBarang(infotypeBarang x);
void insertBarang(ListBarang &L, addressBarang P);
void deleteBarang(ListBarang &L, std::string id);
addressBarang findBarang(ListBarang L, std::string id);

#endif
