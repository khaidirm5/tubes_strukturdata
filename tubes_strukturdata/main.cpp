//
//  main.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 06/12/25.
//

#include <iostream>
#include "toko.h"
#include "barang.h"
#include "relasi.h"

#include "listtoko.h"
#include "listbarang.h"
#include "listrelasi.h"

using namespace std;

int main() {
    ListToko LT;
    ListBarang LB;
    ListRelasi LR;

    createListToko(LT);
    createListBarang(LB);
    createListRelasi(LR);

    int pilihan;
    do {
        cout << "\nINI ADALAH BAGIAN A SAMPAI E\n";
        cout << "1. Tambah Toko\n";
        cout << "2. Tambah Barang\n";
        cout << "3. Hubungkan Toko dan Barang\n";
        cout << "4. Hapus Toko\n";
        cout << "5. Hapus Barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            infotypeToko x;
            inputToko(x);
            addressToko P = buatElmToko(x);
            insertToko(LT, P);
            cout << "Toko berhasil ditambahkan.\n";

        } else if (pilihan == 2) {
            infotypeBarang y;
            inputBarang(y);
            addressBarang Q = buatElmBarang(y);
            insertBarang(LB, Q);
            cout << "Barang berhasil ditambahkan.\n";

        } else if (pilihan == 3) {
            string idT, idB;
            cout << "ID Toko   : ";
            cin >> idT;
            cout << "ID Barang : ";
            cin >> idB;

            addressToko T = findToko(LT, idT);
            addressBarang B = findBarang(LB, idB);

            if (T != nullptr && B != nullptr) {
                addressRelasi R = buatRelasi(T, B);
                insertRelasi(LR, R);
                cout << "Relasi toko-barang dibuat.\n";
            } else {
                cout << "ID tidak ditemukan!\n";
            }

        } else if (pilihan == 4) {
            string id;
            cout << "Masukkan ID toko yang akan dihapus: ";
            cin >> id;

            addressToko T = findToko(LT, id);
            if (T != nullptr) {
                deleteRelasiToko(LR, T);
                deleteToko(LT, id);
                cout << "Toko dan relasinya berhasil dihapus.\n";
            } else {
                cout << "Toko tidak ditemukan.\n";
            }

        } else if (pilihan == 5) {
            string id;
            cout << "Masukkan ID barang yang akan dihapus: ";
            cin >> id;

            addressBarang B = findBarang(LB, id);
            if (B != nullptr) {
                deleteRelasiBarang(LR, B);
                deleteBarang(LB, id);
                cout << "Barang dan relasinya berhasil dihapus.\n";
            } else {
                cout << "Barang tidak ditemukan.\n";
            }
        }

    } while (pilihan != 0);

    return 0;
}

