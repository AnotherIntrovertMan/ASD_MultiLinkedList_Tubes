#ifndef DAERAH_H_INCLUDED
#define DAERAH_H_INCLUDED

#include <iostream>
using namespace std;


#define Next(P) P->Next
#define Prev(P) P->Prev
#define First(L) L.First
#define Last(L) L.Last
#define info(P) P->info

struct datadaerah{
    string namaprovinsi;
};

typedef struct elmDaerah *add_daerah;

struct elmDaerah{
    datadaerah info;
    add_daerah Next;
    add_daerah Prev;
};

struct ListDaerah{
    add_daerah First;
    add_daerah Last;
};

void createList(ListDaerah &L);
void insertFirst(ListDaerah &L, add_daerah P);
void insertLast(ListDaerah &L, add_daerah P);
void deleteFirst(ListDaerah &L, add_daerah &P);
void deleteLast(ListDaerah &L, add_daerah &P);
void printInfo(ListDaerah L);
add_daerah alokasi(datadaerah x);
add_daerah findElm(ListDaerah L, string dae);
void deleteprec(ListDaerah &L, add_daerah &prec);
void dealokasidaerah(add_daerah &P);
void DeleteAfterdaerah(ListDaerah &L, add_daerah prec, add_daerah &P);
#endif // DAERAH_H_INCLUDED
