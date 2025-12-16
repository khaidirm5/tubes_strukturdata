# Data Penjualan – Multi Linked List

## Deskripsi Singkat
Proyek **Data Penjualan** merupakan implementasi struktur data **multi linked-list**
untuk memodelkan hubungan antara **Toko** dan **Barang** beserta relasi keduanya.
Satu toko dapat menjual banyak barang, dan satu barang dapat dijual oleh banyak toko
(relasi M ke N).

Project ini dibuat untuk memenuhi spesifikasi tugas Struktur Data dengan batasan
maksimal **5 toko** dan **3 barang per toko**, serta telah melalui proses pengujian
untuk seluruh kemungkinan interaksi user dan perbaikan bug.

## Fitur
- Input data toko (maksimal 5 toko)
- Input data barang dan relasinya (maksimal 3 barang per toko)
- Menampilkan seluruh data toko dan barang
- Mencari barang pada toko tertentu
- Mencari toko yang menjual barang tertentu
- Menampilkan statistik toko terlengkap dan tersedikit
- Menghapus data toko beserta seluruh relasinya
- Menghapus data barang dari seluruh toko
- Menghapus barang dari toko tertentu
- Validasi input dan penanganan kesalahan user

## Instalasi

### Menggunakan Xcode
1. Buka Xcode
2. Pilih Create a new Xcode Project
3. Pilih Command Line Tool
4. Pilih Language: C++
5. Tambahkan file berikut ke dalam project:
   main.cpp  
   listtoko.h  
   listtoko.cpp  
   listbarang.h  
   listbarang.cpp  
   listrelasi.h  
   listrelasi.cpp  
6. Jalankan program dengan tombol Run

### Menggunakan Code::Blocks
1. Buka Code::Blocks
2. Pilih Create a new project
3. Pilih Console Application
4. Pilih C++
5. Tambahkan file berikut ke dalam project:
   main.cpp  
   listtoko.h  
   listtoko.cpp  
   listbarang.h  
   listbarang.cpp  
   listrelasi.h  
   listrelasi.cpp  
6. Jalankan program dengan Build and Run (F9)

## Penggunaan
Setelah program dijalankan, akan tampil menu berikut:
1. Input data toko  
2. Input data barang & relasi  
3. Tampilkan seluruh data  
4. Cari barang di toko tertentu  
5. Cari toko yang menjual barang tertentu  
6. Statistik toko terlengkap/tersedikit  
7. Hapus data toko  
8. Hapus data barang  
9. Hapus barang dari toko tertentu  
0. Keluar  

User memilih nomor menu dan mengikuti instruksi input yang ditampilkan.

## Contoh
Contoh alur penggunaan program:
Input toko dengan ID T01 dan nama Toko Makmur, kemudian input barang B01 dengan nama
Beras dan harga 12000, maka hasil tampil data adalah:
T01 | Toko Makmur  
B01 | Beras (Rp 12000)  
Total Nilai Barang: Rp 12000  

Jika user memilih menu hapus barang dan memasukkan ID B01, maka barang tersebut akan
terhapus dari seluruh toko yang menjualnya.

## Lisensi
Tugas Besar Struktur Data IFX-49-01PJJ
Kelompok 21

## Kontak / Kontribusi
khaidir.maulana67@gmail.com
auliaaayudyah@gmail.com
