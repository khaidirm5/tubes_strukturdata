//
//  main.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 06/12/25.
//

#include <iostream>
#include "listtoko.h"
#include "listbarang.h"
#include "listrelasi.h"

using namespace std;


void tampilkanSemuaData(ListToko LT, ListRelasi LR) {
    if (LT.first == nullptr) {
        cout << "Belum ada data toko.\n";
        return;
    }

    addressToko T = LT.first;
    while (T) {
        cout << T->info.idToko << " | " << T->info.namaToko << endl;
        addressRelasi R = LR.first;
        bool ada = false;
        int total = 0;

        while (R) {
            if (R->toko == T) {
                cout << "  " << R->barang->info.idBarang
                     << " | " << R->barang->info.namaBarang
                     << " (Rp " << R->barang->info.harga << ")\n";
                total += R->barang->info.harga;
                ada = true;
            }
            R = R->next;
        }

        if (!ada) cout << "  (Belum ada barang)\n";
        cout << "  Total Nilai Barang: Rp " << total << "\n\n";
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
    do {
        cout << "\n===== MENU DATA PENJUALAN =====\n";
        cout << "1. Input data toko (Poin a)\n";
        cout << "2. Input data barang & Relasi (Poin b & c)\n";
        cout << "3. Tampilkan seluruh data (Poin f)\n";
        cout << "4. Cari Barang di Toko Tertentu (Poin g)\n";
        cout << "5. Cari Toko yang Jual Barang Tertentu (Poin h)\n";
        cout << "6. Statistik Toko Terlengkap dan Sedikit (Poin i)\n";
        cout << "7. Hapus Data Toko (Poin d)\n";
        cout << "8. Hapus Data Barang (Poin e)\n";
        cout << "9. Hapus Barang dari Toko Tertentu (Poin e)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            if (LT.count >= 5) {
                cout << "Data toko maksimal 5\n";
                continue;
            }
            infotypeToko x;
            inputToko(x);
            insertToko(LT, buatElmToko(x));
        }

        else if (menu == 2) {
            if (LT.first == nullptr) {
                cout << "Belum ada toko.\n";
                continue;
            }

            string id;
            cout << "ID Toko: ";
            getline(cin, id);

            addressToko T = findToko(LT, id);
            if (!T) {
                cout << "Toko tidak ditemukan.\n";
                continue;
            }

            if (hitungBarangToko(LR, T) >= 3) {
                cout << "Data barang maksimal 3\n";
                continue;
            }

            infotypeBarang b;
            inputBarang(b);
            addressBarang B = buatElmBarang(b);
            insertBarang(LB, B);
            insertRelasi(LR, buatRelasi(T, B));
        }

        else if (menu == 3) tampilkanSemuaData(LT, LR);

        else if (menu == 4) {
            string id;
            cout << "ID Toko: ";
            getline(cin, id);
            addressToko T = findToko(LT, id);
            if (T) printBarangByToko(LR, T);
            else cout << "Toko tidak ditemukan.\n";
        }

        else if (menu == 5) {
            string id;
            cout << "ID Barang: ";
            getline(cin, id);
            addressBarang B = findBarang(LB, id);
            if (B) printTokoByBarang(LR, B);
            else cout << "Barang tidak ditemukan.\n";
        }

        else if (menu == 6) cariTokoEkstrem(LT, LR);

        else if (menu == 7) {
            string id;
            cout << "ID Toko: ";
            getline(cin, id);
            addressToko T = findToko(LT, id);
            if (T) {
                deleteAllRelasiToko(LR, T);
                deleteToko(LT, id);
            }
        }

        else if (menu == 8) {
            string id;
            cout << "ID Barang: ";
            getline(cin, id);
            addressBarang B = findBarang(LB, id);
            if (B) {
                deleteAllRelasiBarang(LR, B);
                deleteBarang(LB, id);
                deleteBarangTanpaRelasi(LB, LR);
            } else cout << "Barang tidak ditemukan.\n";
        }

        else if (menu == 9) {
            string t, b;
            cout << "ID Toko   : ";
            getline(cin, t);
            cout << "ID Barang : ";
            getline(cin, b);
            addressToko T = findToko(LT, t);
            addressBarang B = findBarang(LB, b);
            if (T && B) {
                if (!deleteRelasiTokoBarang(LR, T, B))
                    cout << "Barang tersebut tidak dijual di toko ini.\n";
                deleteBarangTanpaRelasi(LB, LR);
            }
        }

    } while (menu != 0);

    return 0;
}

