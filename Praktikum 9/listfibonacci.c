// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 7 November 2022
// Topik praktikum  : Praktikum 9 - Struktur Berkait
// Deskripsi        : Program yang membuat implementasi list fibonacci

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    if (el == 0)
    {
        PrintInfo(fibonacci);
    } else if (el == 1)
    {
        int elmt;
		scanf("%d", &elmt);
		InsVLast(&fibonacci, elmt);
		
        PrintInfo(fibonacci);
    } else
    {
		int bil1, bil2;
		scanf("%d", &bil1);
		scanf("%d", &bil2);
		
		InsVLast(&fibonacci, bil1);
		InsVLast(&fibonacci, bil2);
		
		int i = 2;
		address a = First(fibonacci);
		address b = Next(a);
		
		while (i < el)
		{
			infotype next = Info(a) + Info(b);
			
			address p = Alokasi(next);
			InsertLast(&fibonacci, p);
			
			// InsVLast(&fibonacci, next);
			
			a = Next(a);
			b = Next(b);
			
			i += 1;
		}
		
        PrintInfo(fibonacci);
    }

    return 0;
}
