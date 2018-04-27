#include "daerah.h"

//Circular Double List

add_daerah alokasi(datadaerah x){
    add_daerah P = new elmDaerah;
    info(P) = x;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void dealokasidaerah(add_daerah &P){
    delete P;
}

void createList(ListDaerah &L){
    First(L) = NULL;
    Last(L) = NULL;
}

void insertFirst(ListDaerah &L, add_daerah P){
    if (First(L)==NULL && Last(L)==NULL){
        First(L) = P;
        Last(L) = P;
        Next(P) = First(L);
        Prev(P) = Last(L);
    }else{
        Next(P) = First(L);
        Prev(First(L)) = Prev(P);
        First(L) = P;
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
    }
}

void insertLast(ListDaerah &L, add_daerah P){
   if (First(L)==NULL && Last(L)==NULL){
        Last(L) = P;
        First(L) = P;
        Next(P) = First(L);
        Prev(P) = Last(L);
    }else{
       Next(Last(L)) = P;
       Prev(P) = Last(L);
       Last(L) = P;
       Prev(First(L)) = Last(L);
       Next(Last(L)) = First(L);
    }
}

void printInfo(ListDaerah L){
    if (First(L)==NULL){
        cout<<"Data Masih Kosong"<<endl;;
    }else{
        add_daerah P;
        P = First(L);
        while (Next(P) != First(L)){
            cout<<"-----------------------------------"<<endl;
            cout<<"Provinsi: "<<info(P).namaprovinsi<<endl;
            cout<<"-----------------------------------";
            cout<<endl;
            P = Next(P);
        }
        if (P!=First(L)){
            cout<<"-----------------------------------"<<endl;
            cout<<"Provinsi: "<<info(P).namaprovinsi<<endl;
            cout<<"-----------------------------------";
            cout<<endl;
        }
    }
}

void deleteFirst(ListDaerah &L, add_daerah &P){
    if (First(L)==NULL&&Last(L)==NULL){
        cout<<"Data Masih Kosong";
    }else if (Next(First(L))==First(L) && Prev(Last(L))==Last(L)){
        P = First(L);
        First(L) = NULL;
        Last(L) = NULL;
        Next(P) = NULL;
        Prev(P) = NULL;
    }else{
        P = First(L);
        First(L) = Next(P);
        Prev(First(L)) = Last(L);
        Next(Last(L)) = First(L);
        Next(P) = NULL;
        Prev(P) = NULL;
    }
}

void deleteLast(ListDaerah &L, add_daerah &P){
    if (First(L)==NULL && Last(L)==NULL){
        cout<<"Data Masih Kosong";
    }else if (Next(First(L))==First(L) && Prev(Last(L))==Last(L)){
       P = First(L);
       First(L) = NULL;
       Last(L) = NULL;
    }else{
        P = Last(L);
        Last(L) = Prev(P);
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
        Next(P) = NULL;
        Prev(P) = NULL;
        }
    }


add_daerah findElm(ListDaerah L, string prov){
    add_daerah P=First(L);
    while(P != NULL){
        if (info(P).namaprovinsi== prov){
            return P;
        }else if ((P==NULL)&& (info(P).namaprovinsi!=prov)){
            return NULL;
        }
        P=Next(P);
    }
    return 0;
}

void deleteprec(ListDaerah &L, add_daerah &prec) {
   add_daerah Q;
   if ((First(L)==NULL)&&(Last(L)==NULL)) {
    cout<<"KOSONG"<<endl; }
   else {
    if (Next(First(L)) == prec && Prev(Last(L)) == prec) {
        First(L) = NULL;
        Last(L) = NULL;
        Next(prec) = NULL;
        Prev(prec) = NULL;
    }
    else if(prec == First(L)){
        deleteFirst(L,prec);
    }
    else if (prec==Last(L)){
        deleteLast(L,prec);
    }else if (Next(Next(prec))==First(L)){

    }
    else {
        Q = Prev(prec);
        Next(Q)=Next(prec);
        Prev(Next(prec))=Q;
        Next(prec)=NULL;
        Prev(prec)=NULL;

        }
    }
}

void DeleteAfterdaerah(ListDaerah &L, add_daerah prec, add_daerah &P){
    if (First(L)==NULL && Last(L)==NULL){
        cout<<"Data Masih Kosong"<<endl;
    }else if (Next(First(L))==First(L) && Prev(Last(L))==Last(L)){
       P = First(L);
       First(L) = NULL;
       Last(L) = NULL;
       Next(P) = NULL;
       Prev(P) = NULL;
    }else{
        if (Next(prec)==First(L)){
            deleteFirst(L,prec);
        }else if (Next(Next(prec))==First(L)){
            deleteLast(L,prec);
        }else{
            P = Next(prec);
            Next(prec) = Next(P);
            Prev(Next(P)) = prec;
            Next(P) = NULL;
            Prev(P) = NULL;
        }
    }

}
