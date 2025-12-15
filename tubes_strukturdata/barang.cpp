//
//  barang.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "barang.h"
#include <iostream>
#include <string>

using namespace std;

void inputBarang(infotypeBarang &x) {
    string temp;

    cout << "Masukkan ID Barang   : ";
    getline(cin, x.idBarang);

    cout << "Masukkan Nama Barang : ";
    getline(cin, x.namaBarang);

    cout << "Masukkan Harga       : ";
    getline(cin, temp);
    x.harga = stoi(temp);   // konversi string → int
}
