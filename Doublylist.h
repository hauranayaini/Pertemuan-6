#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

// Definisi struktur data kendaraan
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList* address;

// Definisi elemen Doubly Linked List
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Definisi kontrol List
struct List {
    address First;
    address Last;
};

// Fungsi & Prosedur Soal 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool isNopolExists(List L, string nopol);

// Fungsi & Prosedur Soal 2 & 3
address findElm(List L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
