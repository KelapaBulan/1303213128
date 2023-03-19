#include "BIOSKOP.h"

using namespace std;


void createListPenonton(ListFilm &L){
    first(L) = NULL;
}
void createListFilm(ListFilm &L){
    first(L) = NULL;
    last(L) = NULL;
}
adrPenonton newPenonton(infotypePenonton x){
    adrPenonton p = new elmPenonton;
    infoPenonton(p) = x;
    nextPenonton(p) = NULL;
    child(p) = NULL;
    return p;
}
adrFilm newFilm(infotypeFilm x){
    adrFilm p = new elmFilm;
    infoFilm(p).judul = x.judul;
    infoFilm(p).durasi = x.durasi;
    nextFilm(p) = NULL;
    prevFilm(p) = NULL;
    return p;
}
adrConect newConect(adrFilm x){
    adrConect p = new elmConect;
    conect(p) = x;
    nextConect(p) = NULL;
    return p;
}

/*Menambahkan data penonton.*/
void insertPenontonFirst(Listpenonton &L, adrPenonton P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        P = first(L);
        first(L) = P;
    }
}
void insertPenontonLast(Listpenonton &L, adrPenonton P){
    adrPenonton y;
    if (first(L) == NULL){
        first(L) = P;
    }else{
        y = first(L);
        while (nextPenonton(y) != NULL){
            y = nextPenonton(y);
        }
        nextPenonton(y) = P;
    }
}

void insertFilmFirst(ListFilm &L, adrFilm P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else {
        nextFilm(P) = first(L);
        prevFilm(first(L)) = P;
        nextFilm(last(L)) = P;
        prevFilm(P) = last(L);
        first(L) = P;
    }
}
void insertFilmlast(ListFilm &L, adrFilm P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else {
        nextFilm(last(L)) = P;
        prevFilm(P) = last(L);
        nextFilm(P) = first(L);
        prevFilm(first(L)) = P;
        last(L) = P;
    }
}

adrPenonton searchPenonton(Listpenonton L, string nama){
    adrPenonton y = first(L);
    if (first(L) == NULL){
        cout << "Tidak Ada Penonton" << endl;
    }else{
        while(nama != infoPenonton(y) && y != NULL){
            y = nextPenonton(y);
        }
        if (infoPenonton(y) == nama){
            return y;
        }else{
            cout << "Penonton tidak ditemukan" << endl;
        }

    }
}

adrFilm searchFilm(ListFilm L, string film){
    adrFilm y = first(L);
    if (first(L) == NULL){
        cout << "Tidak Ada Film" << endl;
    }else{
        while(film != infoFilm(y).judul && nextFilm(y) != first(L)){
            y = nextFilm(y);
        }
        if (infoFilm(y).judul == film){
           return y;
        }else {
            cout << "film tidak ditemukan" << endl;
        }

    }
}

void InsertConect(adrPenonton &D, adrConect P){
    if (child(D) == NULL){
        child(D) = P;
    }else {
        nextConect(P) = child(D);
        child(D) = P;
    }
}

void deletePenontonFirst(Listpenonton &L, adrPenonton &P){
    if (first(L) == NULL){
        cout << "Penonton Tidak Ada" << endl;
    }else {
        P = first(L);
        first(L) = next(P);
        nextPenonton(P) = NULL;
        child(P) = NULL;
    }
}
void deletePenontonLast(Listpenonton &L, adrPenonton &P){
    adrPenonton y;
    if (first(L) == NULL){
        cout << "Penonton Tidak Ada" << endl;
    }else {
        y = first(L);
        while (nextPenonton(nextPenonton(y)) != NULL){
            y = nextPenonton(y);
        }
        P = nextPenonton(y);
        child(P) = NULL;
        nextPenonton(y) = NULL;
    }
}

adrConect searchConectPenonton(adrPenonton D, string judul){
    adrPenonton y;
    //adrConect z;
    Listpenonton L;
    if (first(L) == NULL){
        cout << "Tidak Ada Penonton" << endl;
    }else {
        y = first(L);
        while (nextPenonton(y) != NULL && judul != infoFilm(conect(child(y))).judul){
            y = nextPenonton(y);
        }
        if (judul == infoFilm(conect(child(y))).judul){
            return child(y);
        }
    }
}



