// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 12 November 2022
// Topik praktikum  : Pra-Praktikum 10 - Variasi List Linier
// Deskripsi        : Program yang membuat implementasi dari listsirkuler.h

#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *value = (ElmtList *) malloc(sizeof (ElmtList));

    if (value != Nil)
    {
        Info(value) = X;
        Next(value) = Nil;
        return value;
    } else
    {
        return Nil;
    }
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);

    if (IsEmpty(L))
    {
        return Nil;
    } else
    {
        do
        {
            if (Info(p) == X)
            {
                return p;
            } else
            {
                p = Next(p);
            }
        } while (p != First(L));

        return Nil;       
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertFirst(L, p);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertLast(L, p);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p;
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(p);
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p;
    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L))
    {
        Next(P) = P;
    } else
    {
        address last = First(*L);

        while (Next(last) != First(*L))
        {
            last = Next(last);
        }

        // Next(last) = First(*L), artinya pointer sudah berada di elemen terakhir
        Next(P) = First(*L);
        Next(last) = P;
    }

    First(*L) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmpty(*L))
    {
        InsertFirst(L, P);
    } else
    {
        address last = First(*L);

        while (Next(last) != First(*L))
        {
            last = Next(last);
        }

        // Next(last) = First(*L), artinya pointer sudah berada di elemen terakhir
        Next(P) = First(*L);
        Next(last) = P;
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);

    if (Next(First(*L)) == First(*L))   // List dengan satu elemen
    {
        First(*L) = Nil;
    } else
    {
        address last = First(*L);

        while (Next(last) != First(*L))
        {
            last = Next(last);
        }

        // Next(last) = First(*L), artinya pointer sudah berada di elemen terakhir
        First(*L) = Next(First(*L));
        Next(last) = First(*L); // First(*L) sudah berubah ke elemen setelah elemen pertama sebelumnya
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    *P = First(*L);
    address precLast = Nil;

    while (Next(*P) != First(*L))
    {
        precLast = *P;
        *P = Next(*P);
    }

    // Next(*P) = First(*L), artinya pointer sudah berada di elemen terakhir
    if (precLast == Nil)    // kasus satu elemen
    {
        First(*L) = Nil;
    } else
    {
        Next(precLast) = First(*L);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);

    if (*Pdel == First(*L))
    {
        First(*L) = Next(First(*L));
    }
    
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p = Search(*L, X);

    if (p != Nil)   // X ada
    {
        if (p == First(*L))
        {
            DelFirst(L, &p);
        } else
        {
            address prev = First(*L);

            while (Next(prev) != p)
            {
                prev = Next(prev);
            }

            //Next(prev) = p
            DelAfter(L, &p, prev);
            Dealokasi(p);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");

    if (!IsEmpty(L))
    {
        address p = First(L);

        do
        {
            printf("%d", Info(p));
            p = Next(p);
            if (p != First(L))
            {
                printf(",");
            }
        } while (p != First(L));
    }

    printf("]");
}

// int main()
// {
//     List L1;
//     CreateEmpty(&L1);
//     printf("1 : Berhasil membuat list\n");
//     PrintInfo(L1); printf("\n");

//     // address p = Alokasi(6);
//     // InsertLast(&L1, p);
//     // printf("Berhasil memasukkan 6 ke dalam list\n");
//     // PrintForward(L1); printf("\n");

//     InsVLast(&L1, 6);
//     InsVLast(&L1, 7);
//     InsVLast(&L1, 8);
//     InsVFirst(&L1, 5);
//     InsVFirst(&L1, 4);
//     InsVFirst(&L1, 3);
//     printf("2 : Berhasil memasukkan angka ke list\n");
//     PrintInfo(L1); printf("\n");

//     address p = Alokasi(1);
//     InsertFirst(&L1, p);
//     address q = Alokasi(9);
//     InsertLast(&L1, q);
//     address r = Alokasi(2);
//     InsertAfter(&L1, r, p);
//     printf("3 : Berhasil memasukkan address ke dalam list\n");
//     PrintInfo(L1); printf("\n");

//     address satu;
//     DelFirst(&L1, &satu);
//     address semb;
//     DelLast(&L1, &semb);

//     DelP(&L1, 2);
//     PrintInfo(L1); printf("\n");

//     infotype elmt_awal;
//     DelVFirst(&L1, &elmt_awal);
//     infotype elmt_akhir;
//     DelVLast(&L1, &elmt_akhir);
//     printf("4 : Berhasil menghapus elemen\n");
//     PrintInfo(L1); printf("\n");

//     address b = Search(L1, 7);
//     printf("5 : Terdapat nilai dalam list\n");

//     address after = Alokasi(8);
//     InsertAfter(&L1, after, b);
//     printf("6 : Berhasil menambahkan elemen\n");
//     PrintInfo(L1); printf("\n");

//     address ambil8;
//     DelAfter(&L1, &ambil8, b);
//     printf("7 : Berhasil menghapus elemen\n");
//     PrintInfo(L1); printf("\n");

//     Dealokasi(ambil8);
//     printf("8 : Berhasil dealokasi\n");

//     return 0;
// }