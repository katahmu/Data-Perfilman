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

// List Aktor
struct elmAktor
{
    Aktor info;
    adrAktor next;
};

struct ListAktor
{
    adrAktor first;
};

// List child (film)

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

// List relasi
struct elmRelasi
{
    adrAktor toAktor;
    adrRelasi next;
};

void createListAktor(ListAktor &LA); // Buat List Aktor Baru
void createListFilm(ListFilm &LF);   // Buat List Film Baru

// Tambah Aktor/Film/Relasi Baru
adrAktor newAktor(Aktor x);
adrFilm newFilm(Film x);
adrRelasi newRelasi(adrAktor pA);

// Aktor (SLL)
void insertFirstAktor(ListAktor &LA, adrAktor p);               // Poin 1 & 6. Tambah Aktor di paling awal
void insertLastAktor(ListAktor &LA, adrAktor p);                // Poin 1 & 6. Tambah Aktor di paling akhir
void deleteFirstAktor(ListAktor &LA, adrAktor &p);              // Hapus Aktor Pertama
void deleteLastAktor(ListAktor &LA, adrAktor &p);               // Hapus Aktor Terakhir
void deleteAktorById(ListAktor &LA, ListFilm &LF, int idAktor); // Hapus Aktor Berdasarkan Id
adrAktor findAktorById(ListAktor LA, int idAktor);              // Cari Aktor berdasarkan Id
void showAllAktor(ListAktor LA);                                // Tampilkan Semua Aktor

// Film (DLL)
void insertFirstFilm(ListFilm &LF, adrFilm p);  // Poin 1 & 6.Tambah Film di paling awal
void insertLastFilm(ListFilm &LF, adrFilm p);   // Poin 1 & 6.Tambah Film di paling Akhir
void deleteFirstFilm(ListFilm &LF, adrFilm &p); // Hapus Film Pertama
void deleteLastFilm(ListFilm &LF, adrFilm &p);  // Hapus Film Terakhir
void deleteFilmById(ListFilm &LF, int idFilm);  // Hapus Film berdasarkan Id
adrFilm findFilmById(ListFilm LF, int idFilm);  // Cari Film berdasarkan Id
void showAllFilm(ListFilm LF);                  // Tampilkan Semua Film

// Poin 3. Menghapus data parent beserta relasinya
void deleteAktorById(ListAktor &LA, ListFilm &LF, int idAktor);
void deleteFilmById(ListFilm &LF, int idFilm);

// Poin 4. Mencari data parent
adrAktor findAktorById(ListAktor LA, int idAktor);

// Poin 5. Mencari data child
adrFilm findFilmById(ListFilm LF, int idFilm);

// Relasi
// Poin 7. Menghubungkan Film dengan Aktor
void connectFilmAktor(ListFilm &LF, ListAktor &LA, int idFilm, int idAktor);
// Poin 7. Menghubungkan Aktor dengan Film
void connectAktorFilm(ListAktor &LA, ListFilm &LF, int idAktor, int idFilm);

// Poin 9. Mencari data child pada parent tertentu
adrFilm findFilmByAktor(ListFilm LF, ListAktor LA, int idAktor);

// Poin 10. Menghapus data child pada parent tertentu beserta relasinya
void deleteFilmByAktor(ListFilm &LF, ListAktor &LA, int idAktor, int idFilm);

// Poin 11. Menghitung jumlah data child dari parent tertentu
int countFilmByAktor(ListFilm LF, ListAktor LA, int idAktor);

// Poin 12. Main program
int main();

// Tampilkan
void showFilmWithAktor(ListFilm LF);                          // Poin 8. Tampilkan Film beserta Aktor
void showFilmByAktor(ListFilm LF, ListAktor LA, int idAktor); // Poin 8. Tampilkan Film Berdasarkan Aktor
void showAktorByFilm(ListFilm LF, int idFilm);                // Poin 8. Tampilkan Aktor Berdasarkan Film
void showAktorWithFilm(ListAktor LA, ListFilm LF);          //   Poin 8. Tampilkan aktor beserta Film

// Top
void showTopAktorDanAktris(ListFilm LF, ListAktor LA); // Tampilkan Aktor paling ketceh

#endif