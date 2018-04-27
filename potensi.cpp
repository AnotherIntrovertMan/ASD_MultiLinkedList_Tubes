#include "potensi.h"

//Double List

void createList(ListPotensi &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void dealokasipotensi(add_potensi &P){
    delete P;
}

add_potensi alokasi(datapotensi x){
    add_potensi P =new elmPotensi;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(ListPotensi &L, add_potensi P){
    if ((first(L) == NULL)&&(last(L)==NULL)) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(ListPotensi &L, add_potensi P) {
    if((first(L) == NULL)&&(last(L)==NULL)) {
        last(L) = P;
        first(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertBefore(ListPotensi &L,add_potensi P,add_potensi prec) {
    next(P) = prec;
    prev(P) = prev(prec);
    prev(prec) = P;
    next(prev(P)) = P;
}

void insertSort (add_potensi P,ListPotensi &L){
    add_potensi R;
    if ((first(L) == NULL) && (last(L)==NULL)) {
        insertFirst(L,P);
    }else if (info(P).pendapatan <= info(first(L)).pendapatan) {
         insertFirst(L,P);
    }else if (info(P).pendapatan >= info(last(L)).pendapatan) {
        insertLast(L,P);
    }else if ( info(P).pendapatan > info(first(L)).pendapatan ){
         R = first(L);
         while (info(P).pendapatan > info(R).pendapatan) {
             R = next(R);}
         if (info(R).pendapatan>=info(P).pendapatan) {
            insertBefore(L,P,R);
        }
    }
}


void printInfo(ListPotensi L){
    add_potensi P=first(L);
    int i=1;
    while(P!=NULL){
        cout<<"Data Potensi : "<<i<<endl;
        cout<<"Potensi      : "<<info(P).potensi<<endl;
        cout<<"Pendapatan   : Rp."<<info(P).pendapatan<<endl;
        cout<<" "<<endl;
        i++;
        P=next(P);
}
}

void deleteFirst(ListPotensi &L, add_potensi &P){
    if ((first(L)==NULL)&&(last(L)==NULL)){
        cout<<"Data Kosong"<<endl;
    }else{
        P = first(L);
        first(L)=next(P);
        next(P)=NULL;
        prev(P)=NULL;
        prev(first(L))=NULL;

    }
}

void deleteLast(ListPotensi &L, add_potensi &P){
    if ((first(L)==NULL)&&(last(L)==NULL)){
        cout<<"Data Kosong"<<endl;
    }else{
        P = last(L);
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(P)=NULL;
        next(last(L))=NULL;

    }

}

add_potensi findElm(ListPotensi L, string poten){
    add_potensi P=first(L);
    while(P != NULL){
        if (info(P).potensi== poten){
            return P;
        }else if ((P==NULL)&& (info(P).potensi!=poten)){
            return NULL;
        }
        P=next(P);
    }
}

void deleteprec(ListPotensi &L, add_potensi &prec) {
   add_potensi Q;
   if ((first(L)==NULL)&&(last(L)==NULL)) {
    cout<<"KOSONG"<<endl; }
   else {
    if ((first(L) == prec) && (last(L) == prec)) {
        first(L) = NULL;
        last(L) = NULL;
        next(prec) = NULL;
        prev(prec) = NULL;
    }
    else if( prec == first(L)){
        deleteFirst(L,prec);}
    else if ( prec==last(L)){
        deleteLast(L,prec);}
    else {
        Q = prev(prec);
        next(Q)=next(prec);
        prev(next(prec))=Q;
        next(prec)=NULL;
        prev(prec)=NULL;}}
}
