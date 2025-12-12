//
//  relasi.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef RELASI_H
#define RELASI_H

#include "toko.h"
#include "barang.h"

struct ElmRelasi {
    addressToko toko;
    addressBarang barang;
    ElmRelasi *next;
};

typedef ElmRelasi* addressRelasi;


addressRelasi buatRelasi(addressToko T, addressBarang B);

#endif
