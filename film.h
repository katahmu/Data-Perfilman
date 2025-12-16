#ifndef film_h
#define film_h

#include <string>
#include <iostream>
using namespace std;

// Definisi data
struct Aktor {
    string nama;
    string agensi;
    int umur;
};

struct Film {
    string judul;
    string genre;
    double rating;
};

// Pointer
typedef struct elmAktor *adrAktor;
typedef struct elmFilm *adrFilm;
typedef struct elmRelasi *adrRelasi;

// List child (film)
struct elmFilm {
    Film info;
    adrFilm next;
};

struct ListFilm {
    adrFilm first;
};

// List relasi
struct elmRelasi {
    adrFilm nextFilm;
    adrRelasi next;
};

struct listRelasi {
    adrRelasi first;
};
         