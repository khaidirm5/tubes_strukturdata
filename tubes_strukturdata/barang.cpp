//
//  barang.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "barang.h"
#include <iostream>

void inputBarang(infotypeBarang &x) {
    std::cout << "Masukkan ID Barang: ";
    std::cin >> x.idBarang;

    std::cout << "Masukkan Nama Barang: ";
    std::cin >> x.namaBarang;
}
