//
//  toko.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef TOKO_H
#define TOKO_H

#include <string>

struct Toko {
    std::string idToko;
    std::string namaToko;
};

typedef Toko infotypeToko;

struct ElmToko {
    infotypeToko info;
    ElmToko *next;
};

typedef ElmToko* addressToko;

// TAMBAHKAN INI
void inputToko(infotypeToko &x);

#endif
