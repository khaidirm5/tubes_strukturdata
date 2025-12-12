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

void insertRelasi(ListRelasi &L, addressRelasi R) {
    R->next = L.first;
    L.first = R;
}

void deleteRelasiToko(ListRelasi &L, addressToko T) {
    addressRelasi P = L.first;
    addressRelasi prev = nullptr;

    while (P != nullptr) {
        if (P->toko == T) {
            addressRelasi temp = P;
            if (prev == nullptr) {
                L.first = P->next;
                P = L.first;
            } else {
                prev->next = P->next;
                P = P->next;
            }
            delete temp;
            
        } else {
            prev = P;
            P = P->next;
        }
    }
}

void deleteRelasiBarang(ListRelasi &L, addressBarang B) {
    addressRelasi P = L.first;
    addressRelasi prev = nullptr;

    while (P != nullptr) {
        if (P->barang == B) {
            addressRelasi temp = P;
            if (prev == nullptr) {
                L.first = P->next;
                P = L.first;
            } else {
                prev->next = P->next;
                P = P->next;
            }
            delete temp;
        } else {
            prev = P;
            P = P->next;
        }
    }
}

void printRelasi(ListRelasi L) {
    addressRelasi P = L.first;
    while (P != nullptr) {
        std::cout << P->toko->info.namaToko
                  << " menjual "
                  << P->barang->info.namaBarang << "\n";
        P = P->next;
    }
}

// FITUR LIA
void tampilSemuaTokoBesertaBarang(ListToko LT, ListRelasi LR) {
    addressToko P = LT.first;
    if (P == nullptr) {
        std::cout << "Data toko kosong.\n";
        return;
    }

    std::cout << "\n=== DATA KESELURUHAN TOKO & BARANG ===\n";
    while (P != nullptr) {
        std::cout << "Toko: " << P->info.namaToko << " (ID: " << P->info.idToko << ")\n";
        
        addressRelasi R = LR.first;
        bool adaJualan = false;
        while (R != nullptr) {
            if (R->toko == P) {
                std::cout << "  -> Menjual: " << R->barang->info.namaBarang << "\n";
                adaJualan = true;
            }
            R = R->next;
        }

        if (!adaJualan) {
            std::cout << "  -> (Belum ada barang yang dijual)\n";
        }
        std::cout << "--------------------------------------\n";
        P = P->next;
    }
}

void tampilBarangDariToko(ListToko LT, ListRelasi LR, std::string idToko) {
    addressToko T = findToko(LT, idToko);
    if (T == nullptr) {
        std::cout << "Toko dengan ID " << idToko << " tidak ditemukan.\n";
        return;
    }

    std::cout << "\nDaftar Barang di Toko " << T->info.namaToko << ":\n";
    addressRelasi R = LR.first;
    bool ada = false;
    while (R != nullptr) {
        if (R->toko == T) {
            std::cout << "- " << R->barang->info.namaBarang << " (ID: " << R->barang->info.idBarang << ")\n";
            ada = true;
        }
        R = R->next;
    }
    if (!ada) std::cout << "(Toko ini belum menjual barang apapun)\n";
}

// H. Menampilkan toko yang menjual barang tertentu
void tampilTokoDariBarang(ListBarang LB, ListRelasi LR, std::string idBarang) {
    addressBarang B = findBarang(LB, idBarang);
    if (B == nullptr) {
        std::cout << "Barang dengan ID " << idBarang << " tidak ditemukan.\n";
        return;
    }

    std::cout << "\nToko yang menjual " << B->info.namaBarang << ":\n";
    addressRelasi R = LR.first;
    bool ada = false;
    while (R != nullptr) {
        if (R->barang == B) {
            std::cout << "- " << R->toko->info.namaToko << " (ID: " << R->toko->info.idToko << ")\n";
            ada = true;
        }
        R = R->next;
    }
    if (!ada) std::cout << "(Belum ada toko yang menjual barang ini)\n";
}

void tokoPalingLengkapDanSedikit(ListToko LT, ListRelasi LR) {
    addressToko P = LT.first;
    if (P == nullptr) {
        std::cout << "Data toko kosong.\n";
        return;
    }

    addressToko maxToko = nullptr;
    addressToko minToko = nullptr;
    int maxCount = -1;
    int minCount = 999999;

    while (P != nullptr) {
        int count = 0;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->toko == P) {
                count++;
            }
            R = R->next;
        }

        if (count > maxCount) {
            maxCount = count;
            maxToko = P;
        }
        if (count < minCount) {
            minCount = count;
            minToko = P;
        }

        P = P->next;
    }

    std::cout << "\n=== STATISTIK KELENGKAPAN TOKO ===\n";
    if (maxToko != nullptr)
        std::cout << "Toko Paling Lengkap: " << maxToko->info.namaToko << " (" << maxCount << " barang)\n";
    
    if (minToko != nullptr)
        std::cout << "Toko Paling Sedikit: " << minToko->info.namaToko << " (" << minCount << " barang)\n";
}
