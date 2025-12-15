//
//  main.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 06/12/25.
//

#include <iostream>
#include <string>

#include "listtoko.h"
#include "listbarang.h"
#include "listrelasi.h"

using namespace std;

void tampilkanSemuaData(ListToko LT, ListRelasi LR) {
    addressToko T = LT.first;

    while (T != nullptr) {
        cout << "Toko: " << T->info.idToko
             << " | " << T->info.namaToko << endl;
        cout << "Barang yang dijual:\n";

        bool adaBarang = false;
        addressRelasi R = LR.first;

        while (R != nullptr) {
            if (R->toko == T) {
                adaBarang = true;
                cout << "ID: " << R->barang->info.idBarang << endl;
                cout << "Nama: " << R->barang->info.namaBarang << endl;
                cout << "Harga: " << R->barang->info.harga << endl << endl;
            }
            R = R->next;
        }

        if (!adaBarang) {
            cout << "(Belum ada barang)\n\n";
        }
        T = T->next;
    }
}

int main() {
    ListToko LT;
    ListBarang LB;
    ListRelasi LR;

    createListToko(LT);
    createListBarang(LB);
    createListRelasi(LR);

    int menu;
    string input;

    do {
        cout << "===== MENU =====\n";
        cout << "1. Input data toko\n";
        cout << "2. Input data barang (pilih toko)\n";
        cout << "3. Tampilkan seluruh data toko dan barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        getline(cin, input);
        menu = stoi(input);

        if (menu == 1) {
            char lagi;
            do {
                infotypeToko x;
                inputToko(x);
                insertToko(LT, buatElmToko(x));

                cout << "Tambah toko lagi? (y/n): ";
                cin >> lagi;
                cin.ignore();
            } while (lagi == 'y' || lagi == 'Y');
        }

        else if (menu == 2) {
            if (LT.first == nullptr) {
                cout << "Belum ada toko.\n";
                continue;
            }

            cout << "\nDaftar Toko:\n";
            addressToko T = LT.first;
            while (T != nullptr) {
                cout << "- " << T->info.idToko
                     << " (" << T->info.namaToko << ")\n";
                T = T->next;
            }

            string idToko;
            cout << "Pilih ID Toko: ";
            getline(cin, idToko);

            addressToko pilihToko = findToko(LT, idToko);
            if (pilihToko == nullptr) {
                cout << "Toko tidak ditemukan.\n";
                continue;
            }

            char lagi;
            do {
                infotypeBarang b;
                inputBarang(b);

                addressBarang PB = buatElmBarang(b);
                insertBarang(LB, PB);
                insertRelasi(LR, buatRelasi(pilihToko, PB));

                cout << "Tambah barang lagi? (y/n): ";
                cin >> lagi;
                cin.ignore();
            } while (lagi == 'y' || lagi == 'Y');
        }

        else if (menu == 3) {
            tampilkanSemuaData(LT, LR);
        }

    } while (menu != 0);

    return 0;
}
