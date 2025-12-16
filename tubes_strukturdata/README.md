# Tugas Besar Struktur Data - Data Penjualan

**Kelompok 21 - IFX-49-01 PJJ** **Telkom University**

Proyek ini adalah implementasi struktur data **Multi Linked-List** menggunakan bahasa C++ untuk memodelkan sistem pendataan Toko dan Barang dengan relasi **M ke N**.

## Anggota Tim
| Nama | NIM |
| :--- | :--- |
| **Khaidir Maulana** | 103042580001 |
| **Aulia Ayu Dyah Lestari** | 103042580007 |

## Deskripsi Proyek
Aplikasi ini memodelkan hubungan antara **Toko (Parent)** dan **Barang (Child)**.
* Suatu toko bisa menjual banyak barang.
* Suatu barang bisa dijual oleh banyak toko.
* [cite_start]**Batasan:** Maksimal 5 toko dan maksimal 3 barang per toko[cite: 9, 10].

## Fitur Program
Program memiliki fungsionalitas lengkap sebagai berikut :

1.  **Input Data Toko**: Menambah data toko baru (Validasi Max 5).
2.  **Input Data Barang**: Menambah barang ke toko tertentu (Validasi Max 3 per toko).
3.  **Tampilkan Data**: Menampilkan seluruh data toko beserta barang jualannya.
4.  **Cari Barang**: Mencari apakah barang tertentu dijual di toko tertentu.
5.  **Cari Toko**: Mencari daftar toko yang menjual barang tertentu.
6.  **Statistik**: Menampilkan Toko Terlengkap (barang terbanyak) dan Tersedikit.
7.  **Hapus Toko**: Menghapus data toko beserta seluruh relasi penjualannya (*Cascade Delete*).
8.  **Hapus Barang (Global)**: Menghapus data barang dari seluruh toko yang menjualnya.
9.  **Hapus Barang (Spesifik)**: Menghapus barang hanya dari satu toko tertentu.

## Struktur File
Pastikan file-file berikut tersedia dalam direktori project :
* `main.cpp` - Program utama dan menu.
* `listtoko.h` & `listtoko.cpp` - ADT untuk manajemen data Toko.
* `listbarang.h` & `listbarang.cpp` - ADT untuk manajemen data Barang.
* `listrelasi.h` & `listrelasi.cpp` - ADT untuk relasi M-to-N.

## Instalasi & Cara Menjalankan

### Menggunakan Xcode (macOS) 
1.  Buka Xcode, pilih **Create a new Xcode Project**.
2.  Pilih **Command Line Tool**.
3.  Pilih Language: **C++**.
4.  Tambahkan seluruh file `.h` dan `.cpp` ke dalam project navigator.
5.  Jalankan program dengan tombol **Run**.

### Menggunakan Code::Blocks (Windows)
1.  Buka Code::Blocks, pilih **Create a new project**.
2.  Pilih **Console Application**.
3.  Pilih bahasa **C++**.
4.  Tambahkan seluruh file `.h` dan `.cpp` ke dalam project management.
5.  Tekan **F9** (Build and Run) untuk menjalankan.

## Contoh Penggunaan
Berikut adalah simulasi alur program :

1.  User menginput toko: **ID T01**, Nama **Toko Makmur**.
2.  User menginput barang ke toko tersebut: **ID B01**, Nama **Beras**, Harga **12000**.
3.  Saat menu "Tampilkan Data" dipilih, output akan terlihat seperti:

```text
T01 | Toko Makmur
  - B01 | Beras (Rp 12000)
  Total Nilai Barang: Rp 12000
