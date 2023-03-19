#ifndef BIOSKOP_H_INCLUDED
#define BIOSKOP_H_INCLUDED

#include <iostream>
#include <stdio.h>

using namespace std;
#define first(L) ((L).first)
#define last(L) ((L).last)
#define infoPenonton(P) (P)->infoPenonton
#define infoFilm(P) (P)->infoFilm
#define nextPenonton(P) (P)->nextPenonton
#define nextFilm(P) (P)->nextFilm
#define prevFilm(P) (P)->prevFilm
#define nextConect(P) (P)->nextConect
#define child(P) (P)->child
#define conect(P) (P)->Conect


/* ADT Parent */

typedef string infotypePenonton;
typedef struct elmPenonton *adrPenonton;
typedef struct elmConect *adrConect;

struct elmPenonton{
    infotypePenonton infoPenonton;
    adrPenonton nextPenonton;
    adrConect child;
};

struct Listpenonton{
    adrPenonton first;
};


/* ADT child */
typedef struct elmFilm *adrFilm;

struct infotypeFilm{
    string judul;
    int durasi;
};

struct elmFilm{
    infotypeFilm infoFilm;
    adrFilm nextFilm;
    adrFilm prevFilm;

};
struct ListFilm{
    adrFilm first;
    adrFilm last;
};

/* ADT relasi */
typedef struct elmConect *adrConect;

struct elmConect{
     adrFilm Conect;
     adrConect nextConect;
};


/* Primitif */
void createListPenonton(ListFilm &L);
void createListFilm(ListFilm &L);
adrPenonton newPenonton(infotypePenonton x);
adrFilm newFilm(infotypeFilm x);
adrConect newConect(adrFilm x);

/*Menambahkan data penonton.*/
void insertPenontonFirst(Listpenonton &L, adrPenonton P);
void insertPenontonLast(Listpenonton &L, adrPenonton P);

/*Menambahkan data film.*/
void insertFilmFirst(ListFilm &L, adrFilm P);
void insertFilmlast(ListFilm &L, adrFilm P);

/*Mencari data penonton tertentu.*/
adrPenonton searchPenonton(Listpenonton L, string nama);
adrFilm searchFilm(ListFilm L, string film);

/*Menambahkan relasi penonton dengan film yang ditonton.*/
void InsertConect(adrPenonton &D, adrConect P);

/*Mencari data penonton yang menonton film tertentu.*/
adrConect searchConectPenonton(adrPenonton D, string judul);

/*Menghapus data penonton berserta relasinya.*/
void deletePenontonFirst(Listpenonton &L, adrPenonton &P);
void deletePenontonLast(Listpenonton &L, adrPenonton &P);

/*Menghapus data film yang ditonton oleh penonton tertentu.*/
void deleteFilm(adrPenonton &D, adrConect &P);

/*Menampilkan data seluruh penonton dan film yang ditonton.*/
void ShowAll(Listpenonton L);

/*Menghitung banyaknya penonton yang menonton film tertentu.*/
int countPenonton();

/*Menampilkan data film yang paling banyak diminati.*/
void ShowMaxFilm();

#endif // BIOSKOP_H_INCLUDED
