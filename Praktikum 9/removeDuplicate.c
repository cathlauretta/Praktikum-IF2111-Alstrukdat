// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 7 November 2022
// Topik praktikum  : Praktikum 9 - Struktur Berkait
// Deskripsi        : Program yang membuat implementasi list fibonacci

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "removeDuplicate.h"

List removeDuplicate(List l)
/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/
{
	List new;
	CreateEmpty(&new);
	
	address p = First(l);
	
	while (Next(p) != Nil)
	{
		infotype temp = Info(p);
		address q = Next(p);
		
		if (Info(p) != Info(q))
		{
			InsVLast(&new, Info(p));
		}
		
		p = Next(p);
	}
	
	InsVLast(&new, Info(p));
	
	return new;
}

/* 
int main()
{
	List L;
	CreateEmpty(&L);
	
	InsVLast(&L, 1);
	InsVLast(&L, 1);
	InsVLast(&L, 2);
	InsVLast(&L, 2);
	InsVLast(&L, 3);
	InsVLast(&L, 4);
	InsVLast(&L, 5);
	InsVLast(&L, 6);
	InsVLast(&L, 6);
	InsVLast(&L, 7);
	
	PrintInfo(L); printf("\n");

	L = removeDuplicate(L);
	
	PrintInfo(L); printf("\n");
	
	return 0;
}
*/
