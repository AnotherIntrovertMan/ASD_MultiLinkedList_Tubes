#ifndef POTENSI_H_INCLUDED
#define POTENSI_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct datapotensi{
    string potensi;
    int pendapatan;
};

typedef struct elmPotensi *add_potensi;

struct elmPotensi{
    datapotensi info;
    add_potensi next;
    add_potensi prev;
};

struct ListPotensi{
    add_potensi first;
    add_potensi last;
};

void createList(ListPotensi &L);
void insertFirst(ListPotensi &L, add_potensi P);
void insertLast(ListPotensi &L, add_potensi P);
void insertBefore(ListPotensi &L,add_potensi P,add_potensi prec);
void insertSort (add_potensi P,ListPotensi &L);
void printInfo(ListPotensi L);
add_potensi alokasi(datapotensi x);
void deleteFirst(ListPotensi &L, add_potensi &P);
void deleteLast(ListPotensi &L, add_potensi &P);
add_potensi findElm(ListPotensi L, string poten);
void deleteprec(ListPotensi &L, add_potensi &prec);
void dealokasipotensi(add_potensi &P);



#endif // POTENSI_H_INCLUDED
