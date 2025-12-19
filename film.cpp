#include "film.h"

// Buat List Aktor Baru
void createListAktor(ListAktor &LA)
{
    LA.first = NULL;
}
// Buat List Film Baru
void createListFilm(ListFilm &LF)
{
    LF.first = LF.last = NULL;
}
// Node Baru
adrAktor newAktor(Aktor x)
{
    adrAktor p = new elmAktor;
    p->info = x;
    p->next = NULL;
    return p;
}

adrFilm newFilm(Film x)
{
    adrFilm p = new elmFilm;
    p->info = x;
    p->prev = p->next = NULL;
    p->firstRel = NULL;
    return p;
}
adrRelasi newRelasi(adrAktor pA)
{
    adrRelasi r = new elmRelasi;
    r->toAktor = pA;
    r->next = NULL;
    return r;
}

// Aktor
//  Tambah Aktor ke paling awal
void insertFirstAktor(ListAktor &LA, adrAktor p)
{
    p->next = LA.first;
    LA.first = p;
}
// Tambah Aktor ke paling Terakhir
void insertLastAktor(ListAktor &LA, adrAktor p)
{
    if (LA.first == NULL)
    {
        LA.first = p;
    }
    else
    {
        adrAktor q = LA.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}
// Hapus Aktor yang di paling awal
void deleteFirstAktor(ListAktor &LA, adrAktor &p)
{
    p = LA.first;
    if (p == NULL)
        return;
    LA.first = p->next;
    p->next = NULL;
}
// Hapus Aktir yang di paling Akhir
void deleteLastAktor(ListAktor &LA, adrAktor &p)
{
    p = NULL;
    if (LA.first == NULL)
        return;

    if (LA.first->next == NULL)
    {
        p = LA.first;
        LA.first = NULL;
        return;
    }

    adrAktor prev = NULL;
    adrAktor cur = LA.first;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    p = cur;
}
// Hapus Aktor berdasrkan Id

// Cari Aktor berdasarkan Id
adrAktor findAktorById(ListAktor LA, int idAktor)
{
    adrAktor p = LA.first;
    while (p != NULL && p->info.id != idAktor)
        p = p->next;
    return p;
}
// Tampilkan semua aktor
void showAllAktor(ListAktor LA)
{
    adrAktor p = LA.first;
    while (p != NULL)
    {
        cout << "ID:" << p->info.id
             << " | " << p->info.nama
             << " | " << p->info.agensi
             << " | umur:" << p->info.umur
             << " | " << (p->info.gender == 'F' ? "Aktris" : "Aktor")
             << "\n";
        p = p->next;
    }
}
//
// Film
// Tambah Film di paling awal
void insertFirstFilm(ListFilm &LF, adrFilm p) 
{
    if (LF.first == NULL)
    {
        LF.first = LF.last = p;
    }
    else
    {
        p->next = LF.first;
        LF.first->prev = p;
        LF.first = p;
    }
};

// Tambah Film di paling Akhir
void insertLastFilm(ListFilm &LF, adrFilm p) 
{
    if (LF.first == NULL)
    {
        LF.first = LF.last = p;
    }
    else
    {
        LF.last->next = p;
        p->prev = LF.last;
        LF.last = p;
    }
};

// Hapus Film Pertama
void deleteFirstFilm(ListFilm &LF, adrFilm &p) 
{
    p = LF.first;
    if (p == NULL)
        return;
    if (LF.first == LF.last)
    {
        LF.first = LF.last = NULL;
    }
    else
    {
        LF.first = p->next;
        LF.first->prev = NULL;
        p->next = NULL;
    }
};

// Hapus Film Terakhir
void deleteLastFilm(ListFilm &LF, adrFilm &p) {};
// Hapus Film berdasarkan Id
void deleteFilmById(ListFilm &LF, int idFilm) {};
// Cari Film berdasarkan Id
adrFilm findFilmById(ListFilm LF, int idFilm) {};
// Tampilkan Semua Film
void showAllFilm(ListFilm LF);

// Relasi
// Menghubungkan Film dengan Aktor
void connectFilmAktor(ListFilm &LF, ListAktor &LA, int idFilm, int idAktor) {};
// Hapus Aktor dari sebuah Film
bool deleteAktorFromFilm(ListFilm &LF, int idFilm, int idAktor) {};
// Hitung Aktor yang ada di dalam Film
int countAktorInFilm(ListFilm LF, int idFilm) {};

// Tampilkan
// Tampilkan Film beserta Aktor
void showFilmWithAktor(ListFilm LF) {};
// Tampilkan Film Berdasarkan Aktor
void showFilmByAktor(ListFilm LF, ListAktor LA, int idAktor) {};
// Tampilkan Aktor Berdasarkan Film
void showAktorByFilm(ListFilm LF, int idFilm) {};

// Top
// Tampilkan Aktor paling ketceh
void showTopAktorDanAktris(ListFilm LF, ListAktor LA) {};
