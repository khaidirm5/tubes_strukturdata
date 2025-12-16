//
//  listrelasi.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#include "listrelasi.h"
#include <iostream>

void createListRelasi(ListRelasi &L) {
    L.first = nullptr;
}

addressRelasi buatRelasi(addressToko T, addressBarang B) {
    addressRelasi P = new elmRelasi;
    P->toko = T;
    P->barang = B;
    P->next = nullptr;
    return P;
}

void insertRelasi(ListRelasi &L, addressRelasi P) {
    P->next = L.first;
    L.first = P;
}

void deleteAllRelasiToko(ListRelasi &L, addressToko T) {
    addressRelasi P = L.first, prev = nullptr;
    while (P) {
        if (P->toko == T) {
            addressRelasi del = P;
            if (!prev) L.first = P->next;
            else prev->next = P->next;
            P = P->next;
            delete del;
        } else {
            prev = P;
            P = P->next;
        }
    }
}

void deleteAllRelasiBarang(ListRelasi &L, addressBarang B) {
    addressRelasi P = L.first, prev = nullptr;
    while (P) {
        if (P->barang == B) {
            addressRelasi del = P;
            if (!prev) L.first = P->next;
            else prev->next = P->next;
            P = P->next;
            delete del;
        } else {
            prev = P;
            P = P->next;
        }
    }
}

bool deleteRelasiTokoBarang(ListRelasi &L, addressToko T, addressBarang B) {
    addressRelasi P = L.first, prev = nullptr;
    while (P) {
        if (P->toko == T && P->barang == B) {
            if (!prev) L.first = P->next;
            else prev->next = P->next;
            delete P;
            return true;
        }
        prev = P;
        P = P->next;
    }
    return false;
}

int hitungBarangToko(ListRelasi L, addressToko T) {
    int count = 0;
    addressRelasi P = L.first;
    while (P) {
        if (P->toko == T) count++;
        P = P->next;
    }
    return count;
}

/* ====== OUTPUT ====== */

void printBarangByToko(ListRelasi L, addressToko T) {
    addressRelasi P = L.first;
    bool ada = false;
    while (P) {
        if (P->toko == T) {
            cout << P->barang->info.idBarang << " "
                 << P->barang->info.namaBarang << endl;
            ada = true;
        }
        P = P->next;
    }
    if (!ada) cout << "(Tidak ada barang)\n";
}

void printTokoByBarang(ListRelasi L, addressBarang B) {
    addressRelasi P = L.first;
    bool ada = false;
    while (P) {
        if (P->barang == B) {
            cout << P->toko->info.idToko << endl;
            ada = true;
        }
        P = P->next;
    }
    if (!ada) cout << "(Tidak ada toko)\n";
}

void cariTokoEkstrem(ListToko LT, ListRelasi LR) {
    addressToko T = LT.first;
    if (!T) {
        cout << "Belum ada toko.\n";
        return;
    }

    addressToko maxT = T, minT = T;
    int max = hitungBarangToko(LR, T);
    int min = max;

    T = T->next;
    while (T) {
        int j = hitungBarangToko(LR, T);
        if (j > max) { max = j; maxT = T; }
        if (j < min) { min = j; minT = T; }
        T = T->next;
    }

    cout << "Toko Terlengkap : " << maxT->info.idToko
         << " (" << max << " barang)\n";
    cout << "Toko Tersedikit : " << minT->info.idToko
         << " (" << min << " barang)\n";
}

void printTokoByNamaBarang(ListRelasi LR, string namaBarang) {
    std::cout << "Toko yang menjual '" << namaBarang << "':" << std::endl;
    addressRelasi P = LR.first;
    bool found = false;

    while (P != nullptr) {
        if (P->barang->info.namaBarang == namaBarang) {
            std::cout << "- " << P->toko->info.namaToko << std::endl;
            found = true;
        }
        P = P->next;
    }

    if (!found) {
        std::cout << "(Barang tidak ditemukan di toko manapun)" << std::endl;
    }
}
void searchBarangInToko(ListRelasi LR, addressToko T, std::string keyword) {
    if (T == nullptr) return;

    std::cout << "Mencari '" << keyword << "' di Toko " << T->info.namaToko << "...\n";
    
    addressRelasi P = LR.first;
    bool found = false;

    while (P != nullptr) {
        // Cek apakah relasi ini milik toko T?
        if (P->toko == T) {
            // Cek apakah ID Barang COCOK -ATAU- Nama Barang COCOK dengan keyword
            if (P->barang->info.idBarang == keyword || P->barang->info.namaBarang == keyword) {
                std::cout << "DITEMUKAN! Barang: " << P->barang->info.namaBarang
                          << " (ID: " << P->barang->info.idBarang << ")"
                          << " | Harga: " << P->barang->info.harga << std::endl;
                found = true;
            }
        }
        P = P->next;
    }

    if (!found) {
        std::cout << "Barang '" << keyword << "' TIDAK dijual di toko ini." << std::endl;
    }
}
