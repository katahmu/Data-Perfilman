#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
using namespace std;

// Definisi data
struct Aktor
{
    int id;
    string nama;
    string agensi;
    int umur;
    char gender;
};

struct Film
{
    int id;
    string judul;
    string genre;
    double rating;
};

// Pointer
typedef struct elmAktor *adrAktor;
typedef struct elmFilm *adrFilm;
typedef struct elmRelasi *adrRelasi;

// List Aktor (List Child - independen / Single Linked List)
struct elmAktor
{
    Aktor info;
    adrAktor next;
};

struct ListAktor
{
    adrAktor first;
};

// List film (List parent - memiliki relasi / Double Linked List)

struct elmFilm
{
    Film info;
    adrFilm prev;
    adrFilm next;
    adrRelasi firstRel;
};

struct ListFilm
{
    adrFilm first;
    adrFilm last;
};

// List relasi (Menunjuk ke aktor)
struct elmRelasi
{
    adrAktor toAktor; // pointer ke aktor
    adrRelasi next;
};

// Fungsi dan Prosedur

// 0. Membuat List & Elemen Baru
void createListAktor(ListAktor &LA); // Buat List Aktor Baru
void createListFilm(ListFilm &LF);   // Buat List Film Baru
adrAktor newAktor(Aktor x);          // Buat Node Aktor Baru
adrFilm newFilm(Film x);             // Buat Node Film Baru
adrRelasi newRelasi(adrAktor pA);    // Buat Node Relasi Baru

// 1. Manajemen aktor (list child)
// Insert First & last (Poin 1 & 6)
void insertFirstAktor(ListAktor &LA, adrAktor p);
void insertLastAktor(ListAktor &LA, adrAktor p);

// Delete (Poin 3: Menghapus data child beserta relasinya)
void deleteFirstAktor(ListAktor &LA, adrAktor &p);
void deleteLastAktor(ListAktor &LA, adrAktor &p);
void deleteAktorById(ListAktor &LA, ListFilm &LF, int idAktor);

// Search & Show (Poin 5: Mencari data child)
adrAktor findAktorById(ListAktor LA, int idAktor);
void showAllAktor(ListAktor LA);

// 2. Manajemen film (list parent)
// Insert First & last (Poin 1)
void insertFirstFilm(ListFilm &LF, adrFilm p);
void insertLastFilm(ListFilm &LF, adrFilm p);

// Delete (Poin 3: Menghapus data parent beserta relasinya)
void deleteFirstFilm(ListFilm &LF, adrFilm &p);
void deleteLastFilm(ListFilm &LF, adrFilm &p);
void deleteFilmById(ListFilm &LF, int idFilm);

// Search & Show (Poin 4: Mencari data parent)
adrFilm findFilmById(ListFilm LF, int idFilm);
void showAllFilm(ListFilm LF); // Poin 2: show all parent

// 3. Manajemen relasi
// Poin 7. menghubungkan parent ke child
void connectFilmAktor(ListFilm &LF, ListAktor &LA, int idFilm, int idAktor);

// Poin 9. Mencari data child pada parent tertentu
adrFilm findAktorInFilm(ListFilm LF, int idFilm, int idAktor);

// Point 10. Menghapus data child pada parent tertentu
// Menghapus aktor x dari film y
void deleteAktorFromFilm(ListFilm &LF, int idFilm, int idAktor);

// Poin 11. Menghitung jumlah data child dari parent tertentu
int countAktorInFilm(adrFilm pFilm);

// Fitur Tambahan
// Poin 8. Menampilkan data parent beserta child
void showfilmByAktor(ListFilm LF, ListAktor LA, int idAktor);

// Menampilkan data film yang dibintangi oleh aktor tertentu
void showFilmWithAktor(ListFilm LF);

// Menampilkan data aktor yang membintangi film tertentu
void showAktorWithFilm(ListAktor LA, ListFilm LF, int idFilm);

// Poin i. Menampilkan Top 1 Akotr & Aktris
void showTopAktorDanAktris(ListFilm LF, ListAktor LA);

//Generate ID 
int generateAktorId(ListAktor LA);
int generateFilmId(ListFilm LF);
#endif