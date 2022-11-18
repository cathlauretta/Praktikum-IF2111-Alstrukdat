// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 12 November 2022
// Topik praktikum  : Pra-Praktikum 10 - Variasi List Linier
// Deskripsi        : Program yang membuat implementasi dari listdp.h

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return First(L) == Nil && Last(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    ElmtList *value = (ElmtList *) malloc(sizeof (ElmtList));

    if (value != Nil)   // Berhasil dialokasi
    {
        Info(value) = X;
        Next(value) = Nil;
        Prev(value) = Nil;
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);

    if (IsEmpty(L))
    {
        return Nil;
    } else
    {
        while (p != Nil)
        {
            if (Info(p) == X)
            {
                return p;
            } else
            {
                p = Next(p);
            }
        }
    }

    return p;
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
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p;
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(p);
}

void DelVLast (List *L, infotype *X)
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
    Next(P) = First(*L);
    
    if (!IsEmpty(*L))
    {
        Prev(First(*L)) = P;
    } else  // List merupakan list kosong
    {
        Last(*L) = P;
    }

    First(*L) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    Prev(P) = Last(*L);

    if (!IsEmpty(*L))
    {
        Next(Last(*L)) = P;
    } else  // List merupakan list kosong
    {
        First(*L) = P;
    }

    Last(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);

    if (Next(Prec) != Nil)
    {
        Prev(Next(Prec)) = P;
    } else  // Next(Prec) = Nil, artinya Prec berada di Last L
    {
        Last(*L) = P;
    }

    Next(Prec) = P;
    Prev(P) = Prec;
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    Prev(P) = Prev(Succ);

    if (Prev(Succ) != Nil)
    {
        Next(Prev(Succ)) = P;
    } else  // Prev(Succ) = Nil, artinya Prev berada di First L
    {
        First(*L) = P;
    }

    Prev(Succ) = P;
    Next(P) = Succ;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);

    if (First(*L) == Last(*L))  // List satu elemen
    {
        Last(*L) = Nil;
    } else
    {
        Prev(Next(First(*L))) = Nil;
    }

    First(*L) = Next(First(*L));
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L);

    if(First(*L) == Last(*L))
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else
    {
        Next(Prev(*P)) = Nil;
    }

    Last(*L) = Prev(*P);
    // Dealokasi(*P);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p = Search(*L, X);

    if (p != Nil) // X ada
    {
        address q;

        if (p == First(*L))
        {
            DelFirst(L, &q);
        } else if (p == Last(*L))
        {
            DelLast(L, &q);
        } else
        {
            q = First(*L);

            while (Info(q) != X)
            {
                q = Next(q);
            }

            // Info(q) = X
            Prev(Next(q)) = Prev(q);
            Next(Prev(q)) = Next(q);

            Next(q) = Nil;
            Prev(q) = Nil;
        }

        Dealokasi(q);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);

    if (Next(*Pdel) != Nil)
    {
        Prev(Next(*Pdel)) = Prec;
    } else  // Next(*Pdel) = Nil, artinya *Pdel = Last(*L)
    {
        Last(*L) = Prec;
    }

    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);

    if (Prev(*Pdel) != Nil)
    {
        Next(Prev(*Pdel)) = Succ;
    } else  // Prev(*Pdel) = Nil, artinya *Pdel = First(*L)
    {
        First(*L) = Succ;
    }

    Next(*Pdel) = Nil;
    Prev(*Pdel) =  Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");

    if (!IsEmpty(L))
    {
        address p = First(L);

        while (p != Nil)
        {
            printf("%d", Info(p));
            p = Next(p);
            if (p != Nil)
            {
                printf(",");
            }
        }
    }

    printf("]");
}

void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");

    if (!IsEmpty(L))
    {
        address p = Last(L);

        while (p != Nil)
        {
            printf("%d", Info(p));
            p = Prev(p);
            if (p != Nil)
            {
                printf(",");
            }
        }
    }

    printf("]");
}

// int main()
// {
//     List L1;
//     CreateEmpty(&L1);
//     printf("1 : Berhasil membuat list\n");

//     // address p = Alokasi(6);
//     // InsertLast(&L1, p);
//     // printf("1.5 : Berhasil memasukkan 6 ke dalam list\n");
//     // PrintForward(L1); printf("\n");

//     InsVLast(&L1, 6);
//     InsVLast(&L1, 7);
//     InsVLast(&L1, 8);
//     // InsVFirst(&L1, 5);
//     // InsVFirst(&L1, 4);
//     // InsVFirst(&L1, 3);
//     PrintForward(L1); printf("\n");
//     printf("2 : Berhasil memasukkan angka ke list\n");

//     // address p = Alokasi(1);
//     // InsertFirst(&L1, p);
//     address q = Alokasi(9);
//     InsertLast(&L1, q);
//     printf("3 : Berhasil memasukkan address ke list\n");

//     // address r = Alokasi(2);
//     // InsertAfter(&L1, r, p);
//     // address o = Alokasi(0);
//     // InsertBefore(&L1, o, p);

//     PrintForward(L1); printf("\n");
//     PrintBackward(L1); printf("\n");
//     printf("4 : Berhasil mencetak list ke layar\n");

//     // address nol;
//     // DelFirst(&L1, &nol);
//     address semb;
//     DelLast(&L1, &semb);

//     DelP(&L1, 6);
//     PrintForward(L1); printf("\n4.5 : Berhasil menghapus 6\n");

//     infotype elmt_awal;
//     DelVFirst(&L1, &elmt_awal);
//     printf("4.7 : Berhasil menghapus elemen pertama\n");

//     infotype elmt_akhir;
//     DelVLast(&L1, &elmt_akhir);
//     printf("5 : Berhasil menghapus elemen terakhir\n");
//     PrintForward(L1); printf("\n");

//     address a = Search(L1, 4);
//     if (a == Nil) printf("Tidak ada 4 dalam list\n");
//     else printf("6 : Terdapat 4 dalam list dgn address : %d\n", a);

//     InsVFirst(&L1, 7);
//     address b = Search(L1, 7);
//     if (b == Nil) printf("Tidak ada 7 dalam list\n");
//     else printf("7 : Terdapat 7 dalam list dgn address : %d\n", b);

//     address after = Alokasi(8);
//     InsertAfter(&L1, after, b);
//     printf("8 : Berhasil menambahkan elemen\n");
//     PrintForward(L1); printf("\n");

//     address ambil8;
//     DelAfter(&L1, &ambil8, b);
//     printf("9 : Berhasil menghapus elemen\n");
//     PrintForward(L1); printf("\n");

//     Dealokasi(ambil8);
//     printf("10 : Berhasil dealokasi\n");

//     return 0;
// }