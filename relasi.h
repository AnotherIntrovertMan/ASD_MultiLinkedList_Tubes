#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "potensi.h"
#include "daerah.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmRelasi *add_relasi;

struct elmRelasi{
    add_daerah parent;
    add_potensi child;
    add_relasi next;
};

struct ListRelasi{
    add_relasi first;
};

void createList(ListRelasi &L);
add_relasi alokasi(add_daerah Q, add_potensi C);
void insertFirst(ListRelasi &L, add_relasi P);
void printInfo(ListRelasi L);
void printInfoParent(ListRelasi L, string per);
void printInfoChild(ListRelasi L, string ten);
void deleteFirst(ListRelasi &L,add_relasi &P);
void deleteLast(ListRelasi &L,add_relasi &P);
void DeletePrec(ListRelasi &L,add_relasi prec);
void cleandeletedaerah(ListRelasi &L,string vinsi);
void cleandeletepotensi(ListRelasi &L,string daer);


#endif // RELASI_H_INCLUDED
