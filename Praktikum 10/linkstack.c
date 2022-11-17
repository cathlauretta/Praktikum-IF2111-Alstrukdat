// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 14 November 2022
// Topik praktikum  : Praktikum 10 - Variasi List Linier
// Deskripsi        : Program yang membuat implementasi dari linkstack.h

#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
{
	*P = Nil;
	Node *value = (Node *) malloc(sizeof (Node));
	
	if (value != Nil)
	{
		Info(value) = X;
		Next(value) = Nil;
		*P = value;
	}
}

void Dealokasi(address P)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
	return Top(S) == Nil;
}

void CreateEmpty(Stack *S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{
	Top(*S) = Nil;
}

void Push(Stack *S, ElType X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
	address p;
	Alokasi(&p, X);
	
	if (p != Nil)
	{
		Next(p) = Top(*S);
		Top(*S) = p;
	}
}

void Pop(Stack *S, ElType *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
	*X = InfoTop(*S);
	
	address p = Top(*S);
	
	Top(*S) = Next(Top(*S));
	Next(p) = Nil;
}
