//
//  barang.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef BARANG_H
#define BARANG_H

#include <string>

struct Barang {
    std::string idBarang;
    std::string namaBarang;
    int harga;
};

typedef Barang infotypeBarang;

struct ElmBarang {
    infotypeBarang info;
    ElmBarang *next;
};

typedef ElmBarang* addressBarang;

void inputBarang(infotypeBarang &x);

#endif


