// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 7 November 2022
// Topik praktikum  : Praktikum 9 - Struktur Berkait
// Deskripsi        : Program yang membuat representasi dari cache

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
	int N, Q;
	scanf("%d", &N);
	scanf("%d", &Q);
	
	List cache;
	CreateEmpty(&cache);
	
	int i = 1;
	while (i != N + 1)
	{
		address p = Alokasi(i);
		InsertLast(&cache, p);
		i += 1;
	}
	
	// PrintInfo(cache); printf("\n");
	
	int val;
	i = 1;
	while (i != Q + 1)
	{
		scanf("%d", &val);
		
		address q = Search(cache, val);
		
		if (q != Nil)
		{
			DelP(&cache, val);
			
			InsVFirst(&cache, val);
			
			printf("hit ");
			PrintInfo(cache); printf("\n");
		} else
		{
			address r;
			DelLast(&cache, &r);
			Dealokasi(&r);
			
			InsVFirst(&cache, val);
			
			printf("miss ");
			PrintInfo(cache); printf("\n");
		}
		
		i += 1;
	}
}
