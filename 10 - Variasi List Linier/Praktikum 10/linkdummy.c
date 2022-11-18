// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 14 November 2022
// Topik praktikum  : Praktikum 10 - Variasi List Linier
// Deskripsi        : Program yang membuat implementasi dari linkdummy.h

#include <stdio.h>
#include <stdlib.h>
#include "linkdummy.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L)
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */
{
	return First(L) == Last(L);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L)
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */
{
	First(*L) = Nil;
	Last(*L) = Nil;
	
	address dummy = Alokasi(0);
	
	if (dummy != Nil)
	{
		First(*L) = dummy;
		Last(*L) = dummy;
	}
}

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	Node *value = (Node *) malloc(sizeof (Node));

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

/****************** SEARCHING ******************/
address Search(List L, ElType X)
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address p = First(L);
	
	if (IsEmpty(L))
    {
        return Nil;
    } else
    {
        while (Next(p) != Last(L))
        {
            if (Info(p) == X)
            {
                return p;
            } else
            {
                p = Next(p);
            }
        }
        
        // Next(p) = Last(L) = dummy elmt
		return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X)
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
{
	address p = Alokasi(X);
	
	if (p != Nil)
	{
		Next(p) = First(*L);
		First(*L) = p;
	}
}

void InsertLast(List *L, ElType X)
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */
{
	address p = Alokasi(X);
	
	if (p != Nil)
	{
		if (IsEmpty(*L))
		{
			InsertFirst(L, X);
		} else
		{
			address last = First(*L);
			
			while (Next(last) != Last(*L))
			{
				last = Next(last);
			}
			
			// Next(last) = Last(*L) = dummy element
			Next(last) = p;
			Next(p) = Last(*L);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X)
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	address p = First(*L);
	*X = Info(p);
	
	First(*L) = Next(p);
	Next(p) = Nil;
}

void DeleteLast(List *L, ElType *X)
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
{
	address p = First(*L), prevLast = p;
	
	while (Next(p) != Last(*L))
	{
		prevLast = p;
		p = Next(p);
	}
	
	*X = Info(p);
	
	// Next(p) = Last(*L) = dummy elmt
	if (prevLast == p)		// Kasus satu elemen
	{
		First(*L) = Last(*L);
	} else
	{
		Next(prevLast) = Last(*L);
		Next(p) = Nil;
	}
}

/*
void PrintList(List L)
{
	printf("[");
	
	if (!IsEmpty(L))
	{
		address p = First(L);
		
		while (p != Last(L))
		{
			printf("%d", Info(p));
			p = Next(p);
			if (p != Last(L))
			{
				printf(",");
			}
		}
	}
	
	printf("]\n");
}

int main()
{
	List L;
	MakeEmpty(&L);
	
	InsertFirst(&L, 2);
	InsertFirst(&L, 1);
	InsertLast(&L, 3);
	InsertLast(&L, 4);
	
	PrintList(L);
	
	int pertama;
	DeleteFirst(&L, &pertama);
	int terakhir;
	DeleteLast(&L, &terakhir);
	
	printf("%d %d\n", pertama, terakhir);
	
	PrintList(L);
}
*/
