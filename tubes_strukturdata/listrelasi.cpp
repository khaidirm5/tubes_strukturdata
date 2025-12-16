//
//  listrelasi.cpp
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//
#include <iostream>
#include "listrelasi.h"
#include "listtoko.h"
#include "listbarang.h"


void createListRelasi(ListRelasi &L) {
    L.first = nullptr;
}

void insertRelasi(ListRelasi &L, addressRelasi R) {
    R->next = L.first;
    L.first = R;
}

void deleteAllRelasiToko(ListRelasi &L, addressToko T) {
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

void deleteAllRelasiBarang(ListRelasi &L, addressBarang B) {
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
                  << P->barang->info.namaBarang << std::endl;
        P = P->next;
    }
}

void printBarangByToko(ListRelasi LR, addressToko T) {
    if (T == nullptr) return;
    
    std::cout << "\n>> Daftar Barang di Toko: " << T->info.namaToko << std::endl;
    
    addressRelasi P = LR.first;
    bool found = false;
    
    while (P != nullptr) {
        if (P->toko == T) {
            std::cout << "- " << P->barang->info.namaBarang
                      << " (Rp " << P->barang->info.harga << ")" << std::endl;
            found = true;
        }
        P = P->next;
    }
    
    if (!found) {
        std::cout << "(Toko ini belum menjual barang apapun)" << std::endl;
    }
}

void printTokoByBarang(ListRelasi LR, addressBarang B) {
    if (B == nullptr) return;
    
    std::cout << "\n>> Toko yang menjual: " << B->info.namaBarang << std::endl;
    
    addressRelasi P = LR.first;
    bool found = false;
    
    while (P != nullptr) {
        if (P->barang == B) {
            std::cout << "- " << P->toko->info.namaToko << std::endl;
            found = true;
        }
        P = P->next;
    }
    
    if (!found) {
        std::cout << "(Belum ada toko yang menjual barang ini)" << std::endl;
    }
}

void cariTokoEkstrem(ListToko LT, ListRelasi LR) {
    addressToko P = LT.first;
    if (P == nullptr) {
        std::cout << "Data toko kosong." << std::endl;
        return;
    }

    addressToko maxToko = nullptr;
    addressToko minToko = nullptr;
    int maxCount = -1;
    int minCount = 9999;

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

    std::cout << "\n=== STATISTIK TOKO ===" << std::endl;
    if (maxToko != nullptr) {
        std::cout << "Toko Paling Lengkap: " << maxToko->info.namaToko
                  << " (Total: " << maxCount << " barang)" << std::endl;
    }
    if (minToko != nullptr) {
        std::cout << "Toko Paling Sedikit: " << minToko->info.namaToko
                  << " (Total: " << minCount << " barang)" << std::endl;
    }
}
