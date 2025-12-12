#README – Multi Linked List Data Penjualan (Toko & Barang)

Project ini mengimplementasikan **multi linked-list** untuk memodelkan hubungan antara **Toko** dan **Barang**.  
Satu toko dapat menjual banyak barang, dan satu barang dapat dijual oleh banyak toko.

File ini berisi:
1. **Penjelasan struktur dan fungsi bagian A–E (yang sudah selesai)**  
2. **Instruksi lengkap untuk melanjutkan bagian F–I**  

---

# 1. Struktur Project

```
/project
│
├── toko.h
├── toko.cpp
│
├── barang.h
├── barang.cpp
│
├── listtoko.h
├── listtoko.cpp
│
├── listbarang.h
├── listbarang.cpp
│
├── listrelasi.h
├── listrelasi.cpp
│
├── relasi.h
├── relasi.cpp
│
├── main.cpp
│
└── README.md
```

Semua file dipisah agar mudah dikerjakan.

---

# 2. Penjelasan Bagian A–E (Sudah Selesai)

## **A. Penambahan Data Toko (toko.h & toko.cpp)**

Fungsi yang sudah dibuat:
- `inputToko()` — mengisi data toko (ID, nama)
- `createElmToko()` — membuat node toko
- `insertToko()` — memasukkan node toko ke list
- `deleteToko()` — menghapus node toko

Struktur:
- `struct Toko`
- `struct ElmToko`
- `ListToko`

Semua logika list **toko** sudah lengkap.

---

## **B. Penambahan Data Barang (barang.h & barang.cpp)**

Fungsi yang sudah dibuat:
- `inputBarang()`
- `createElmBarang()`
- `insertBarang()`
- `deleteBarang()`

Struktur:
- `struct Barang`
- `struct ElmBarang`
- `ListBarang`

Semua logika list **barang** sudah selesai.

---

## **C. Pembuatan Relasi Toko–Barang (relasi.h & relasi.cpp)**

Fungsi yang sudah dibuat:
- `buatRelasi(addressToko T, addressBarang B)`

Struktur:
- `struct ElmRelasi`
- `ListRelasi`

Relasi menyambungkan **toko** dan **barang** melalui pointer.

---

## **D. Menghapus Toko (toko.cpp)**

Fungsi `deleteToko()` sudah dibuat.  
Catatan: Penghapusan relasi yang terkait toko ini **akan ditangani pada bagian F–I**.

---

## **E. Menghapus Barang (barang.cpp)**

Fungsi `deleteBarang()` sudah tersedia.  
Relasi yang terhubung ke barang akan ditangani pada bagian lanjutan.

---

# 3. Instruksi Melanjutkan Bagian F–I

Bagian berikut harus dikerjakan.  
Struktur dan pondasi datanya sudah lengkap — hanya tinggal menambahkan fungsi baru.

---

## **F. Menampilkan Semua Toko dan Semua Barang yang Dijualnya**

### File yang harus diedit:
- Tambah *deklarasi* di **relasi.h**
- Tambah *implementasi* di **relasi.cpp**
- Tambah menu pemanggil di **main.cpp**

### Fungsi yang harus dibuat:
```
void tampilSemuaTokoBesertaBarang(ListToko LT, ListRelasi LR);
```

### Cara kerja:
1. Loop seluruh toko  
2. Untuk setiap toko, cari relasi yang menunjuk ke toko itu  
3. Tampilkan semua barang yang berelasi dengannya  
4. Jika toko tidak punya relasi → tulis “Tidak menjual barang”  

---

## **G. Menampilkan Barang yang Dijual oleh Satu Toko**

### Tambahkan di:
- Deklarasi → `relasi.h`
- Implementasi → `relasi.cpp`
- Menu → `main.cpp`

### Fungsi yang harus dibuat:
```
void tampilBarangDariToko(addressToko T, ListRelasi LR);
```

### Cara kerja:
- Loop relasi  
- Jika `relasi->toko == T`, tampilkan barangnya  

---

## **H. Menampilkan Toko yang Menjual Satu Barang**

### Tambahkan di:
- `relasi.h`
- `relasi.cpp`
- `main.cpp`

### Fungsi:
```
void tampilTokoYangMenjualBarang(addressBarang B, ListRelasi LR);
```

### Cara kerja:
- Loop relasi  
- Jika `relasi->barang == B`, tampilkan tokonya  

---

## **I. Menentukan Toko dengan Jualan Paling Lengkap dan Paling Sedikit**

### Tambahkan di:
- `relasi.h` (deklarasi)
- `relasi.cpp` (implementasi)
- `main.cpp` (menu)

### Fungsi:
```
addressToko tokoPalingLengkap(ListToko LT, ListRelasi LR);
addressToko tokoPalingSedikit(ListToko LT, ListRelasi LR);
```

### Cara kerja:
1. Untuk setiap toko, hitung jumlah relasi yang mengarah ke barang  
2. Simpan nilai terbesar dan terkecil  
3. Kembalikan alamat tokonya  
4. Tampilkan hasilnya di menu  

---

#4. Catatan untuk Pengerjaan Selanjutnya

- Seluruh fungsi lanjutan **harus ditambah di relasi.cpp**, bukan di file lain  
- Jangan lupa menambahkan *deklarasi* fungsi di relasi.h  
- Menu di main.cpp perlu ditambah untuk memanggil fungsi F–I  
- Gunakan pola kode yang sudah ada agar tetap konsisten  
- Struktur data telah dirapikan agar mudah dikembangkan

---

# Selesai

README ini memuat:
- Penjelasan lengkap bagian A–E  
- Instruksi teknis & detail untuk melanjutkan bagian F–I  

