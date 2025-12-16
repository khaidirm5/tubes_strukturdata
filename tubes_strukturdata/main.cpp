//
//  main.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 06/12/25.
//  Updated for Features G-I
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

    int menu = 0;
    string input;

    do {
        cout << "\n===== MENU DATA PENJUALAN =====\n";
        cout << "1. Input data toko (Poin a)\n";
        cout << "2. Input data barang & Relasi (Poin b & c)\n";
        cout << "3. Tampilkan seluruh data (Poin f)\n";
        cout << "4. Cari Barang di Toko Tertentu (Poin g)\n";
        cout << "5. Cari Toko yang Jual Barang Tertentu (Poin h)\n";
        cout << "6. Statistik Toko Terlengkap/Sedikit (Poin i)\n";
        cout << "7. Hapus Data Toko (Poin d)\n";
        cout << "8. Hapus Data Barang (Poin e)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        getline(cin, input);

        if (input.empty()) continue;
        try {
            menu = stoi(input);
        } catch (...) {
            menu = -1;
        }

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

        else if (menu == 4) {
            string idToko;
            cout << "Masukkan ID Toko: ";
            getline(cin, idToko);

            addressToko T = findToko(LT, idToko);
            if (T != nullptr) {
                printBarangByToko(LR, T);
            } else {
                cout << "Toko dengan ID tersebut tidak ditemukan.\n";
            }
        }

        else if (menu == 5) {
            string idBarang;
            cout << "Masukkan ID Barang: ";
            getline(cin, idBarang);

            addressBarang B = findBarang(LB, idBarang);
            if (B != nullptr) {
                printTokoByBarang(LR, B);
            } else {
                cout << "Barang dengan ID tersebut tidak ditemukan.\n";
            }
        }

        else if (menu == 6) {
            cariTokoEkstrem(LT, LR);
        }

        else if (menu == 7) {
            string idToko;
            cout << "Masukkan ID Toko yang akan dihapus: ";
            getline(cin, idToko);

            addressToko T = findToko(LT, idToko);
            if (T != nullptr) {
                deleteAllRelasiToko(LR, T);
                deleteToko(LT, idToko);
                cout << "Toko dan seluruh data penjualannya berhasil dihapus.\n";
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
        }

        else if (menu == 8) {
            string idBarang;
            cout << "Masukkan ID Barang yang akan dihapus: ";
            getline(cin, idBarang);

            addressBarang B = findBarang(LB, idBarang);
            if (B != nullptr) {
                deleteAllRelasiBarang(LR, B);
                deleteBarang(LB, idBarang);
                cout << "Barang berhasil dihapus dari semua toko.\n";
            } else {
                cout << "Barang tidak ditemukan.\n";
            }
        }

    } while (menu != 0);

    return 0;
}
