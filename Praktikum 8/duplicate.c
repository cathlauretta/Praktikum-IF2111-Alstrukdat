//	NIM				: 18221157
//	Nama			: Cathleen Lauretta
//	Tanggal			: 31 Oktober 2022
//	Topik praktikum : Praktikum 8 - Set & Hash
//	Deskripsi		: Program yang membuat implementasi dari duplicate.h

#include <stdio.h>
#include "duplicate.h"

/*
	Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
		Contoh:
			arrToSet
				<- arr = [1, 1, 3]
				<- arrSize = 3
			-> [1, 3]
*/
Set arrToSet(int *arr, int arrSize)
{
	Set S;
	CreateEmpty(&S);

	int i = 0;

	for (i = 0; i < arrSize; i++)
	{
		if (!IsMember(S, arr[i]))
		{
			Insert(&S, arr[i]);
		}
	}

	return S;
}

/*
	Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
	kemudian kembalikan isinya secara menurun

	Penjelasan Parameter:
	Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
	Parameter 2: arrSize, merupakan panjang arr
	Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
		dan elemen-elemennya terurut menurun
	Parameter 4: arrResSize, merupakan panjang arrRes

	Contoh:
		removeDuplicate
			<- arr = [1, 1, 2, 3]
			<- arrSize = 4
			-> arrRes = [3, 2, 1]
			-> arrResSize = 3
		removeDuplicate
			<- arr = [3, 1, 1]
			<- arrSize = 3
			-> arrRes = [3, 1]
			-> arrResSize = 2
*/
void removeDuplicateDesc(int *arr, int arrSize, int *arrRes, int *arrResSize)
{
	Set Set = arrToSet(arr, arrSize);

	int i, j;
	(*arrResSize) = Set.Count;

	for (i = 0; i < Set.Count; i++)
	{
		arrRes[i] = Set.Elements[i];
	}

	for (i = 0; i < (*arrResSize); i++)
	{
		for (j = i + 1; j < (*arrResSize); j++)
		{
			if (arrRes[j] > arrRes[i])
			{
				int temp = arrRes[i];
				arrRes[i] = arrRes[j];
				arrRes[j] = temp;
			}
		}
	}
}
