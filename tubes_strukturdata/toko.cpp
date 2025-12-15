//
//  toko.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "toko.h"
#include <iostream>

using namespace std;

void inputToko(infotypeToko &x) {
    cout << "Masukkan ID Toko        : ";
    getline(cin, x.idToko);

    cout << "Masukkan Nama Toko      : ";
    getline(cin, x.namaToko);
}
