// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 16 Oktober 2022
// Topik praktikum  : Pra-Praktikum 6 - Queue
// Deskripsi        : Program yang membuat implementasi dari circular_queue.h

#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Q.HEAD == NIL) && (Q.TAIL == NIL);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Length(Q) == Q.MaxEl);
}

int Length (Queue Q)
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
{
    if (IsEmpty(Q))
    {
        return 0;
    } else
    {
        if (Q.TAIL >= Q.HEAD)
        {
            return Q.TAIL - Q.HEAD + 1;
        } else  // Q.TAIL < Q.HEAD : posisi tail berada di sebelah kiri head
        {
            return Q.TAIL - Q.HEAD + Q.MaxEl + 1;
        }
    }
}

int MaxLength (Queue Q)
/* Mengirimkan kapasitas jumlah elemen Q */
{
    return Q.MaxEl;
}

/* *** Kreator *** */
Queue CreateQueue (int Max)
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */
{
    Queue que;
    que.Tab = (ElType *) malloc (Max * sizeof(ElType));

    if (que.Tab != NULL) // periksa alokasi
    {
        que.MaxEl = Max;
        que.HEAD = NIL;
        que.TAIL = NIL;
    } else
    {
        que.MaxEl = 0;
    }

    return que;
}

/* *** Destruktor *** */
void DeleteQueue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */
{
    free((*Q).Tab);
    (*Q).MaxEl = 0;
}

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
{
    if (IsEmpty(*Q))
    {
        (*Q).HEAD = 0;
        (*Q).TAIL = 0;
        (*Q).Tab[0] = X;
    } else
    {
        if ((*Q).TAIL == (*Q).MaxEl - 1) // indeks tail berada di ujung queue
        {
            (*Q).TAIL = 0;
        }else
        {
            (*Q).TAIL += 1;
        }

        (*Q).Tab[(*Q).TAIL] = X;
    }
}

ElType Pop (Queue * Q)
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    ElType val_head;
    val_head = (*Q).Tab[(*Q).HEAD];

    if ((*Q).HEAD == (*Q).TAIL)
    {
        (*Q).HEAD = NIL;
        (*Q).TAIL = NIL;
    } else
    {
        if ((*Q).HEAD == (*Q).MaxEl - 1) // indeks head berada di ujung queue
        {
            (*Q).HEAD = 0;
        } else
        {
            (*Q).HEAD += 1;
        }
    }

    return val_head;
}

ElType Front (Queue Q)
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
{
    return Q.Tab[Q.HEAD];
}