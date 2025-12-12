//
//  toko.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "toko.h"
#include <iostream>

void inputToko(infotypeToko &x) {
    std::cout << "Masukkan ID Toko: ";
    std::cin >> x.idToko;

    std::cout << "Masukkan Nama Toko: ";
    std::cin >> x.namaToko;
}
