#include "daerah.h"
#include "potensi.h"
#include "relasi.h"
#include <iostream>
#include <stdlib.h>
#include<stdio.h>


using namespace std;


//Skema Model 1

ListDaerah LD;
ListPotensi LP;
ListRelasi LR;
add_daerah  A;
add_potensi B;
add_relasi  C;
char yt;

void mainmenu()
{
datadaerah DD;
datapotensi DP;
int menu;
string keluar;
while ((keluar != "Y") && (keluar != "y")){
    cout << "[[=====================================================]]" << endl;
    cout << "[[             TUBES DATA POTENSI DAERAH               ]]" << endl;
    cout << "[[=====================================================]]" << endl;
    cout << "||1. Tambah Data Daerah                                ||" << endl;
    cout << "||2. Tambah Data Potensi                               ||" << endl;
    cout << "||3. Show Data Daerah                                  ||" << endl;
    cout << "||4. Show Data Potensi                                 ||" << endl;
    cout << "||5. Penentuan Relasi                                  ||" << endl;
    cout << "||6. Show Data Relasi                                  ||" << endl;
    cout << "||7. Hapus Data Daerah                                 ||" << endl;
    cout << "||8. Hapus Data Potensi                                ||" << endl;
    cout << "||9. Show Data Daerah Dengan Potensi Tertentu          ||" << endl;
    cout << "||10. Show Data Potensi Yang Dimiliki Daerah Tertentu  ||" << endl;
    cout << "||11. Show Data Daerah Yang Paling Kaya & Miskin       ||" << endl;
    cout << "||12. Keluar                                           ||" << endl;
    cout << "[[=====================================================]]" << endl;
    cout << "MASUKAN MENU PILIHAN : ";
    cin>>menu;
    if (menu == 1){
        system("cls");
        cout<<"================================================"<<endl;
        cout<<"|               Tambah Data Daerah             |"<<endl;
        cout<<"================================================"<<endl;
        cout<<"Masukan Nama Provinsi : ";
        cin>>DD.namaprovinsi;
        A = alokasi(DD);
        insertFirst(LD,A);
        system("cls");


   }else if (menu == 2){
        system("cls");
        cout<<"================================================"<<endl;
        cout<<"|               Tambah Data Potensi            |"<<endl;
        cout<<"================================================"<<endl;
        cout<<"Masukan Nama Potensi : ";
        cin>>DP.potensi;
        cout<<"Masukan Pendapatan   : Rp.";
        cin>>DP.pendapatan;
        B = alokasi(DP);
        insertSort(B,LP);
        system("cls");

    }else if(menu == 3){
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"|                Data Daerah              |"<<endl;
        cout<<"==========================================="<<endl;
        printInfo(LD);
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();

    }else if(menu == 4){
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"|                Data Potensi             |"<<endl;
        cout<<"==========================================="<<endl;
        printInfo(LP);
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();


    } else if (menu == 5) {
        system("cls");
        cout<<"================================================="<<endl;
        cout<<"|                 Penentuan Relasi              |"<<endl;
        cout<<"================================================="<<endl;
        string provin,tensi;
        cout<<"Masukkan Nama Provinsi : ";
        cin>>provin;
        cout<<"Masukkan Potensi       : ";
        cin>>tensi;
        A = findElm(LD,provin);
        B = findElm(LP,tensi);
        if ((A != NULL) && (B != NULL)) {
            cout<<"RELASI BERHASIL"<<endl;
        } else {
            cout<<"GAGAL MEMBUAT RELASI"<<endl;}
        C = alokasi(A,B);
        insertFirst(LR,C);
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();

    }else if(menu == 6){
        system("cls");
        cout<<"================================================="<<endl;
        cout<<"|                 Daerah & Potensi              |"<<endl;
        cout<<"================================================="<<endl;
        printInfo(LR);
        cout<<"Tekan 0 untuk kembali: ";
        char nol;
        cin>>nol;
        while (nol!='0'){
            cout<<"Tekan 0 dong: ";
            cin>>nol;
        }
        system("cls");
        mainmenu();

    }else if(menu == 7){
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"|              Delete Daerah              |"<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Masukkan Nama Provinsi = ";
        string provin;
        cin>>provin;
        add_daerah Q;
        Q = findElm(LD,provin);
        if (Q!=NULL){
            cout<<"Provinsi "<<provin<<" ditemukan"<<endl;
            cout<<"Sudah Dihapus"<<endl;
            deleteprec(LD,Q);
            cleandeletedaerah(LR,provin);

        }else{
            cout<<"Provinsi "<<provin<<" tidak ditemukan"<<endl;
            cout<<"Tidak Bisa Menghapus"<<endl;
        }
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();

    }else if(menu == 8){
        system("cls");
        string tensi;
        cout<<"==========================================="<<endl;
        cout<<"|              Delete Potensi              |"<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Masukkan Jenis Potensi = ";
        cin>>tensi;
        add_potensi Z;
        Z = findElm(LP,tensi);
        if (Z!=NULL){
            cout<<"Potensi "<<tensi<<" ditemukan"<<endl;
            cout<<"Sudah Dihapus"<<endl;
            deleteprec(LP,Z);
            cleandeletepotensi(LR,tensi);
        }else{
            cout<<"Potensi "<<tensi<<" tidak ditemukan"<<endl;
            cout<<"Tidak Bisa Menghapus"<<endl;
        }
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();

    }else if(menu == 9){
        system("cls");
        cout<<"================================================="<<endl;
        cout<<"|         DAERAH DENGAN POTENSI TERTENTU        |"<<endl;
        cout<<"================================================="<<endl;
        cout<<"Masukkan Provinsi : ";
        string pro;
        cin>>pro;
        printInfoParent(LR,pro);
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();

    }else if(menu == 10){
        system("cls");
        cout<<"================================================="<<endl;
        cout<<"|     POTENSI YANG DIMILIKI DAERAH TERTENTU      |"<<endl;
        cout<<"================================================="<<endl;
        string ensi;
        cout<<"Masukkan Jenis Potensi : ";
        cin>>ensi;
        printInfoChild(LR,ensi);
        cout<<"Tekan 0 untuk kembali: ";
            char nol;
            cin>>nol;
            while (nol!='0'){
                cout<<"Tekan 0 dong: ";
                cin>>nol;
            }
            system("cls");
            mainmenu();

    }else if(menu == 11){
        system("cls");
        cout<<"MENU BELUM ADA "<<endl;
        cout<<"Masih bingung "<<endl;

    }else if(menu == 12){
        cout<<" APAKAH ANDA YAKIN INGIN KELUAR? (Y/N)  : ";
        cin>>keluar;


    }
}
}

int main()
{

    createList(LD);
    createList(LP);
    createList(LR);
    mainmenu();
}
