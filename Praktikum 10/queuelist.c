// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 14 November 2022
// Topik praktikum  : Praktikum 10 - Variasi List Linier
// Deskripsi        : Program yang membuat implementasi dari queuelist.h

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{	
	*P = Nil;
	ElmtQueue *value = (ElmtQueue *) malloc(sizeof (ElmtQueue));
	
	if (value != Nil)
	{
		Info(value) = X;
		Next(value) = Nil;
		*P = value;
	}
}

void Dealokasi(address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}

boolean IsEmpty(Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
	return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	if (IsEmpty(Q))
	{
		return 0;
	} else
	{
		address p = Head(Q);
		int count = 0;
		
		while (p != Tail(Q))
		{
			count += 1;
			p = Next(p);
		}
		
		// p = Tail(Q)
		count += 1;
		
		return count;
	}
}

/*** Kreator ***/
void CreateEmpty(Queue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
	address p;
	Alokasi(&p, X);
	
	if (p != Nil)			// Berhasil alokasi
	{
		if (IsEmpty(*Q))
		{
			Head(*Q) = p;
		} else 				// Q tidak kosong
		{
			Next(Tail(*Q)) = p;
		}
		
		Tail(*Q) = p;
	}
}

void Dequeue(Queue *Q, infotype *X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
	*X = InfoHead(*Q);
	address p = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	
	if (Head(*Q) == Nil)	// List menjadi kosong
	{
		Tail(*Q) = Nil;
	}
	
	Next(p) = Nil;
	Dealokasi(p);
}
