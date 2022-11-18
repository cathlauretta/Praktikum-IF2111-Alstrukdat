// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 26 September 2022
// Topik praktikum  : Praktikum 4 - Array dan ADT List
// Deskripsi        : Program yang membuat implementasi dari MinMax.h

#include <stdio.h>
#include "MinMax.h"
#include "list.h"

List MinMax(List L)
{
	int min = Get(L, 0);
	int max = Get(L, 0);
	int idx_min = 0, idx_max = 0;

	for (int i = 1; i < Length(L); i++)
	{
		if (Get(L, i) < min)
		{
			min = Get(L, i);
			idx_min = i;
			
		}
		else if (Get(L, i) > max)
		{
			max = Get(L, i);
			idx_max = i;
		}
	}

	if (idx_min < idx_max)
	{
		DeleteAt((&L), idx_max);
		DeleteAt((&L), idx_min);
	} else
	{
		DeleteAt((&L), idx_min);
		DeleteAt((&L), idx_max);
	}
	
	InsertLast((&L), min);
	InsertLast((&L), max);
	
	return L;
}

// int main()
// {
// 	List L;
// 	L = MakeList();

// 	InsertLast((&L), 1);
// 	printf("%d : %d\n", Length(L), Get(L, 0));
// 	InsertLast((&L), 2);
// 	printf("%d : %d\n", Length(L), Get(L, 1));
// 	InsertLast((&L), 6);
// 	printf("%d : %d\n", Length(L), Get(L, 2));
// 	InsertLast((&L), 4);
// 	printf("%d : %d\n", Length(L), Get(L, 3));
// 	InsertLast((&L), 3);
// 	printf("%d : %d\n", Length(L), Get(L, 4));

// 	L = MinMax(L);
	
// 	for (int i = 0; i <= LastIdx(L); i++)
// 	{
// 		printf("%d ", Get(L, i));
// 	}

// 	return 0;
// }
