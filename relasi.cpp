#include "relasi.h"
#include <iostream>
#include <stdlib.h>
#include<stdio.h>

//Single List

void createList(ListRelasi &L) {
    first(L) = NULL;
}

add_relasi alokasi(add_daerah Q, add_potensi C) {
    add_relasi P = new elmRelasi;
    parent(P) = Q;
    child(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(ListRelasi &L, add_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(ListRelasi L) {
    if (first(L) != NULL) {
        add_relasi P = first(L);
        while(P !=NULL) {
            cout<<"Provinsi    : "<<info(parent(P)).namaprovinsi<<endl;
            cout<<"Potensi     : "<<info(child(P)).potensi<<endl;
            cout<<"Pendapatan  : "<<info(child(P)).pendapatan<<endl;
            cout<<"=================================="<<endl;
            P= next(P);
    }
    } else {
        cout<<"DATA KOSONG"<<endl;
        system("cls");
    }
}

void printInfoParent(ListRelasi L, string per) {
    add_relasi P = first(L);
    while(P !=NULL) {
        if (info(parent(P)).namaprovinsi == per) {
        cout<<"Provinsi    : "<<info(parent(P)).namaprovinsi<<endl;
        cout<<"Potensi     : "<<info(child(P)).potensi<<endl;
        cout<<"Pendapatan  : "<<info(child(P)).pendapatan<<endl;
        cout<<"=================================="<<endl;
        P = next(P);}
        else {
            P = next(P);
        }
    }
}

void printInfoChild(ListRelasi L, string ten) {
    add_relasi P = first(L);
    while(P !=NULL) {
        if (info(child(P)).potensi == ten) {
        cout<<"Potensi  : "<<info(child(P)).potensi<<endl;
        cout<<"Provinsi : "<<info(parent(P)).namaprovinsi<<endl;
        cout<<"=================================="<<endl;
        P = next(P);}
        else {
            P = next(P);
        }
    }
}

void deleteFirst(ListRelasi &L,add_relasi &P) {
    if (first(L) == NULL) {
        cout<<"Kosong";
    } else {
        P = first(L);
        first(L) = next(first(L));
        next(P) = NULL;
        delete P;
    }
}

void deleteLast(ListRelasi &L,add_relasi &P){
    if (first(L) == NULL) {
        cout<<"Kosong";
    } else {
        add_relasi Q;
        P = first(L);
        while(P != NULL) {
            Q = P;
            P = next(P);
        }
        next(Q) =NULL;
        delete P;
    }
}

void DeletePrec(ListRelasi &L,add_relasi prec) {
if (first(L) != NULL) {
    if (first(L) == prec) {
        deleteFirst(L,prec);
    }else if(next(prec)==NULL){
        deleteLast(L,prec);
    } else {
        add_relasi P = first(L);
        while (next(P)!= prec) {
            P=next(P);
        }
        next(P) = next(prec);
        next(prec) = NULL;
    }

}
}



void cleandeletepotensi(ListRelasi &L,string daer){
    add_relasi Q = first(L);
    while (Q != NULL) {
        add_relasi R;
        if (daer == info(child(Q)).potensi) {
            R = Q;
            if (next(Q) != NULL) {
                Q = next(Q);
            } else {
                Q = first(L);
            }
            DeletePrec(L,R);
        } else {
                Q = next(Q);
    }
    }
}

void cleandeletedaerah(ListRelasi &L, string vinsi){
    add_relasi Q = first(L);
    while (Q!=NULL){
        add_relasi R;
        if (vinsi==info(parent(Q)).namaprovinsi){
            R = Q;
            if (next(Q)!=NULL){
                Q = next(Q);
            }else{
                Q = first(L);
            }
            DeletePrec(L,R);
        }else{
            Q = next(Q);
        }
    }
}
