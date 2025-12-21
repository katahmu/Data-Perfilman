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
    p->firstRel = NULL; // list relasi kosong di awal
    return p;
}

adrRelasi newRelasi(adrAktor pA)
{
    adrRelasi r = new elmRelasi;
    r->toAktor = pA;
    r->next = NULL;
    return r;
}

// 1. Manajemen Aktor // Single linked list
// Tambah Aktor ke paling awal
void insertFirstAktor(ListAktor &LA, adrAktor p)
{
    if (LA.first == NULL)
    {
        LA.first = p;
    }
    else
    {
        p->next = LA.first;
        LA.first = p;
    }
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
        {
            q = q->next;
        }
        q->next = p;
    }
}

// Hapus Aktor yang di paling awal
void deleteFirstAktor(ListAktor &LA, adrAktor &p)
{
    p = LA.first;
    if (LA.first != NULL)
    {
        LA.first = p->next;
        p->next = NULL;
    }
}

// Hapus Aktor yang di paling Akhir
void deleteLastAktor(ListAktor &LA, adrAktor &p)
{
    if (LA.first == NULL)
    {
        p = NULL;
    }
    else if (LA.first->next == NULL)
    {
        p = LA.first;
        LA.first = NULL;
    }
    else
    {
        adrAktor q = LA.first;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
    }
}

// Hapus Aktor berdasrkan Id
void deleteAktorById(ListAktor &LA, ListFilm &LF, int idAktor)
{
    // 1. Hapus relasi di film dulu
    adrFilm f = LF.first;
    while (f != NULL)
    {
        deleteAktorFromFilm(LF, f->info.id, idAktor);
        f = f->next;
    }

    // 2. Hapus aktor dari list induk
    adrAktor p = findAktorById(LA, idAktor);
    if (p != NULL)
    {
        if (p == LA.first)
        {
            deleteFirstAktor(LA, p);
        }
        else
        {
            adrAktor prev = LA.first;
            while (prev->next != p)
            {
                prev = prev->next;
            }
            prev->next = p->next;
            p->next = NULL;
        }
    }
}

// Cari Aktor berdasarkan Id
adrAktor findAktorById(ListAktor LA, int idAktor)
{
    adrAktor p = LA.first;
    while (p != NULL)
    {
        if (p->info.id == idAktor)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Tampilkan semua aktor
void showAllAktor(ListAktor LA)
{
    adrAktor p = LA.first;
    cout << "=== Daftar Aktor & Aktris ===\n";
    while (p != NULL)
    {
        cout << "[" << p->info.id << "] " << p->info.nama
             << " (" << p->info.gender << "), "
             << p->info.umur << " thn - " << p->info.agensi << endl;
        p = p->next;
    }
    cout << endl;
}

// 2. Manajemen Film // Double linked list
// Tambah Film di paling awal
void insertFirstFilm(ListFilm &LF, adrFilm p)
{
    if (LF.first == NULL)
    {
        LF.first = p;
        LF.last = p;
    }
    else
    {
        p->next = LF.first;
        LF.first->prev = p;
        LF.first = p;
    }
}

// Tambah Film di paling Akhir
void insertLastFilm(ListFilm &LF, adrFilm p)
{
    if (LF.first == NULL)
    {
        LF.first = p;
        LF.last = p;
    }
    else
    {
        LF.last->next = p;
        p->prev = LF.last;
        LF.last = p;
    }
}

// Hapus Film Pertama
void deleteFirstFilm(ListFilm &LF, adrFilm &p)
{
    p = LF.first;
    if (p != NULL)
    {
        if (LF.first == LF.last) // hanya ada satu film
        {
            LF.first = NULL;
            LF.last = NULL;
        }
        else
        {
            LF.first = p->next;
            LF.first->prev = NULL;
            p->next = NULL;
        }
    }
}

// Hapus Film Terakhir
void deleteLastFilm(ListFilm &LF, adrFilm &p)
{
    p = LF.last;
    if (p != NULL)
    {
        if (LF.first == LF.last) // hanya ada satu film
        {
            LF.first = NULL;
            LF.last = NULL;
        }
        else
        {
            LF.last = p->prev;
            LF.last->next = NULL;
            p->prev = NULL;
        }
    }
}

// Hapus Film berdasarkan Id
void deleteFilmById(ListFilm &LF, int idFilm)
{
    adrFilm p = findFilmById(LF, idFilm);

    if (p != NULL)
    {
        // Hapus semua relasi di dalamnya dulu (Memory Clean up)
        adrRelasi r = p->firstRel;
        while (r != NULL)
        {
            adrRelasi temp = r;
            r = r->next;
            delete temp;
        }

        // Hapus Node Film
        if (p == LF.first)
        {
            deleteFirstFilm(LF, p);
        }
        else if (p == LF.last)
        {
            deleteLastFilm(LF, p);
        }
        else
        {
            // Delete Middle (DLL)
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->next = NULL;
            p->prev = NULL;
        }
    }
}

// Cari Film berdasarkan Id
adrFilm findFilmById(ListFilm LF, int idFilm)
{
    adrFilm p = LF.first;
    while (p != NULL)
    {
        if (p->info.id == idFilm)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Tampilkan Semua Film
void showAllFilm(ListFilm LF)
{
    adrFilm p = LF.first;
    cout << "=== Daftar Film ===" << endl;
    while (p != NULL)
    {
        cout << "[" << p->info.id << "] " << p->info.judul
             << " - " << p->info.genre
             << " (Rating: " << p->info.rating << ")" << endl;
        p = p->next;
    }
    cout << endl;
}

// 3. Manajemen Relasi
// Menghubungkan Film dengan Aktor
void connectFilmAktor(ListFilm &LF, ListAktor &LA, int idFilm, int idAktor)
{
    adrFilm pFilm = findFilmById(LF, idFilm);
    adrAktor pAktor = findAktorById(LA, idAktor);

    if (pFilm != NULL && pAktor != NULL)
    {
        // Cek dulu apakah sudah ada relasi agar tidak duplikat
        if (findAktorInFilm(LF, idFilm, idAktor) == NULL)
        {
            adrRelasi r = newRelasi(pAktor);
            // Insert First Relasi
            r->next = pFilm->firstRel;
            pFilm->firstRel = r;
            cout << "Berhasil menghubungkan " << pAktor->info.nama
                 << " ke film " << pFilm->info.judul << endl;
        }
        else
        {
            cout << "Aktor tersebut sudah ada di film ini!" << endl;
        }
    }
    else
    {
        cout << "ID Film atau ID Aktor tidak valid." << endl;
    }
}

// Mencari aktor membintangi film apa saja
adrFilm findAktorInFilm(ListFilm LF, int idFilm, int idAktor)
{
    adrFilm pFilm = findFilmById(LF, idFilm);
    if (pFilm != NULL)
    {
        adrRelasi r = pFilm->firstRel;
        while (r != NULL)
        {
            if (r->toAktor->info.id == idAktor)
            {
                return pFilm;
            }
            r = r->next;
        }
    }
    return NULL;
}

// Menghapus aktor dari film tertentu
void deleteAktorFromFilm(ListFilm &LF, int idFilm, int idAktor)
{
    adrFilm pFilm = findFilmById(LF, idFilm);
    if (pFilm != NULL)
    {
        adrRelasi r = pFilm->firstRel;
        adrRelasi prev = NULL;

        while (r != NULL)
        {
            if (r->toAktor->info.id == idAktor)
            {
                // Ketemu, hapus
                if (prev == NULL)
                { // Hapus elemen pertama
                    pFilm->firstRel = r->next;
                }
                else
                { // Hapus elemen tengah/akhir
                    prev->next = r->next;
                }
                delete r;
                cout << "Aktor dengan ID " << idAktor
                     << " telah dihapus dari film " << pFilm->info.judul << endl;
                return;
            }
            prev = r;
            r = r->next;
        }
    }
}

// Menghitung jumlah aktor dalam sebuah film
int countAktorInFilm(adrFilm pFilm)
{
    int count = 0;
    adrRelasi r = pFilm->firstRel;
    while (r != NULL)
    {
        count++;
        r = r->next;
    }
    return count;
}

// 4. Tampilan
// Tampilkan Film beserta Aktor
void showFilmWithAktor(ListFilm LF)
{
    adrFilm p = LF.first;
    cout << "=== DAFTAR FILM & PEMAINNYA ===" << endl;
    while (p != NULL)
    {
        cout << "Film: " << p->info.judul << endl;
        adrRelasi r = p->firstRel;
        if (r == NULL)
        {
            cout << "   (Belum ada pemain)" << endl;
        }
        else
        {
            while (r != NULL)
            {
                cout << "   - " << r->toAktor->info.nama << endl;
                r = r->next;
            }
        }
        cout << endl;
        p = p->next;
    }
}

// Tampilkan Film dengan aktor
void showFilmByAktor(ListAktor LA, ListFilm LF, int idAktor)
{
    adrFilm p = LF.first;
    cout << "=== DAFTAR FILM & PEMAINNYA ===" << endl;
    while (p != NULL)
    {
        cout << "Film: " << p->info.judul << endl;
        adrRelasi r = p->firstRel;
        if (r == NULL)
        {
            cout << "   (Belum ada pemain)" << endl;
        }
        else
        {
            while (r != NULL)
            {
                cout << "   - " << r->toAktor->info.nama << endl;
                r = r->next;
            }
        }
        cout << endl;
        p = p->next;
    }
}

// Tampilkan film yang dibintangi oleh aktor tertentu
void showfilmByAktor(ListFilm LF, ListAktor LA, int idAktor)
{
    adrAktor pAktor = findAktorById(LA, idAktor);
    if (pAktor != NULL)
    {
        cout << "Film yang dibintangi " << pAktor->info.nama << ":" << endl;
        bool found = false;

        adrFilm p = LF.first;
        while (p != NULL)
        {
            // Cek relasi di dalam setiap film
            adrRelasi r = p->firstRel;
            while (r != NULL)
            {
                if (r->toAktor == pAktor)
                { // Cek pointer
                    cout << "- " << p->info.judul << " (" << p->info.genre << ")" << endl;
                    found = true;
                    break;
                }
                r = r->next;
            }
            p = p->next;
        }
        if (!found)
            cout << "(Tidak ada film)" << endl;
    }
    else
    {
        cout << "Aktor tidak ditemukan." << endl;
    }
}

// Tampilkan aktor yang membintangi film tertentu
void showAktorWithFilm(ListAktor LA, ListFilm LF, int idFilm)
{
    adrFilm pFilm = findFilmById(LF, idFilm);
    if (pFilm != NULL)
    {
        cout << "Aktor yang membintangi film " << pFilm->info.judul << ":" << endl;
        adrRelasi r = pFilm->firstRel;
        if (r == NULL)
            cout << "(Kosong)" << endl;
        while (r != NULL)
        {
            cout << "- " << r->toAktor->info.nama << endl;
            r = r->next;
        }
    }
    else
    {
        cout << "Film tidak ditemukan." << endl;
    }
}

// Top
// Tampilkan Aktor paling ketceh
void showTopAktorDanAktris(ListFilm LF, ListAktor LA)
{
    // Variabel untuk menyimpan pemenang
    adrAktor topAktor = NULL;
    adrAktor topAktris = NULL;
    int maxAktor = -1;
    int maxAktris = -1;

    adrAktor pA = LA.first;
    while (pA != NULL)
    {
        // Hitung berapa film yg dia bintangi
        int count = 0;

        // Loop semua film untuk cek relasi (Manual count)
        adrFilm pF = LF.first;
        while (pF != NULL)
        {
            adrRelasi r = pF->firstRel;
            while (r != NULL)
            {
                if (r->toAktor == pA)
                {
                    count++;
                    break;
                }
                r = r->next;
            }
            pF = pF->next;
        }

        // Cek Max Logic
        if (pA->info.gender == 'F' || pA->info.gender == 'f')
        { // Cewek
            if (count > maxAktris)
            {
                maxAktris = count;
                topAktris = pA;
            }
        }
        else
        { // Cowok
            if (count > maxAktor)
            {
                maxAktor = count;
                topAktor = pA;
            }
        }
        pA = pA->next;
    }

    cout << "=== TOP ARTIS ===" << endl;
    if (topAktor)
        cout << "Top Aktor  : " << topAktor->info.nama << " (Main di " << maxAktor << " film)" << endl;
    else
        cout << "Top Aktor  : -" << endl;

    if (topAktris)
        cout << "Top Aktris : " << topAktris->info.nama << " (Main di " << maxAktris << " film)" << endl;
    else
        cout << "Top Aktris : -" << endl;
}

// Fungsi Tambahan untuk generate ID agar tidak ada ID yang sama
// Generate id aktor
int generateAktorId(ListAktor LA)
{
    int mx = 0;
    adrAktor p = LA.first;
    while (p != NULL)
    {
        if (p->info.id > mx)
            mx = p->info.id;
        p = p->next;
    }
    return mx + 1;
}

// Generate id Film
int generateFilmId(ListFilm LF)
{
    int mx = 0;
    adrFilm p = LF.first;
    while (p != NULL)
    {
        if (p->info.id > mx)
            mx = p->info.id;
        p = p->next;
    }
    return mx + 1;
}
