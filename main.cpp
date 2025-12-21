#include <iostream>
#include "film.h"

using namespace std;

int main()
{
    ListAktor LA;
    ListFilm LF;

    createListAktor(LA);
    createListFilm(LF);

    int pilih;

    do
    {
        cout << "\n=============================\n";
        cout << "   MENU DATA PERFILMAN\n";
        cout << "=============================\n";
        cout << "1. Tambah Aktor / Aktris\n";
        cout << "2. Tambah Film\n";
        cout << "3. Hubungkan Film dan Aktor\n";
        cout << "4. Hapus Aktor\n";
        cout << "5. Hapus Film\n";
        cout << "6. Tampilkan Semua Aktor\n";
        cout << "7. Tampilkan Semua Film\n";
        cout << "8. Tampilkan Film beserta Aktor\n";
        cout << "9. Tampilkan Film oleh Aktor\n";
        cout << "10. Tampilkan Aktor dalam Film\n";
        cout << "11. Top Aktor & Aktris\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu (contoh: 1): ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
        {
            Aktor a;
            a.id = generateAktorId(LA);
            cout << "ID Aktor : " << a.id << endl;
            cout << "Nama Aktor (contoh: Dion_Wiyoko): ";
            cin >> a.nama;
            cout << "Agensi (contoh: Warner_Bros): ";
            cin >> a.agensi;
            cout << "Umur (contoh: 30): ";
            cin >> a.umur;
            cout << "Gender (M/F, contoh: M): ";
            cin >> a.gender;

            adrAktor p = newAktor(a);
            insertLastAktor(LA, p);
            cout << "Aktor berhasil ditambahkan.\n";
            break;
        }

        case 2:
        {
            Film f;
            f.id = generateFilmId(LF);
            cout << "ID Film : " << f.id << endl;
            cout << "Judul Film (contoh: Sore): ";
            cin >> f.judul;
            cout << "Genre Film (contoh: Drama_Fiksi): ";
            cin >> f.genre;
            cout << "Rating (contoh: 8.1): ";
            cin >> f.rating;

            adrFilm p = newFilm(f);
            insertLastFilm(LF, p);
            cout << "Film berhasil ditambahkan.\n";
            break;
        }

        case 3:
        {
            int idFilm, idAktor;
            cout << "ID Film (contoh: 1): ";
            cin >> idFilm;
            cout << "ID Aktor (contoh: 1): ";
            cin >> idAktor;
            connectFilmAktor(LF, LA, idFilm, idAktor);
            break;
        }

        case 4:
        {
            int id;
            cout << "ID Aktor yang dihapus (contoh: 1): ";
            cin >> id;
            deleteAktorById(LA, LF, id);
            break;
        }

        case 5:
        {
            int id;
            cout << "ID Film yang dihapus (contoh: 1): ";
            cin >> id;
            deleteFilmById(LF, id);
            break;
        }

        case 6:
            showAllAktor(LA);
            break;

        case 7:
            showAllFilm(LF);
            break;

        case 8:
            showFilmWithAktor(LF);
            break;

        case 9:
        {
            int id;
            cout << "ID Aktor (contoh: 1): ";
            cin >> id;
            showfilmByAktor(LF, LA, id);
            break;
        }

        case 10:
        {
            int id;
            cout << "ID Film (contoh: 1): ";
            cin >> id;
            showAktorWithFilm(LA, LF, id);
            break;
        }

        case 11:
            showTopAktorDanAktris(LF, LA);
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak valid.\n";
        }

    } while (pilih != 0);

    return 0;
}
