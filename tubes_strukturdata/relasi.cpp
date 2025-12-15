//
//  relasi.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "relasi.h"

addressRelasi buatRelasi(addressToko T, addressBarang B) {
    addressRelasi R = new ElmRelasi;
    R->toko = T;
    R->barang = B;
    R->next = nullptr;
    return R;
}
