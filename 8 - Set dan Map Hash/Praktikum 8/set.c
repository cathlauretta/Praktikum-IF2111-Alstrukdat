//	NIM				: 18221157
//	Nama			: Cathleen Lauretta
//	Tanggal			: 31 Oktober 2022
//	Topik praktikum : Praktikum 8 - Set & Hash
//	Deskripsi		: Program yang membuat implementasi dari set.h dengan beberapa fungsi tambahan untuk melakukan operasi terhadap ADT Set

#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    boolean found = false;
    int i = 0;

    while (i < (*S).Count && !found)
    {
        if ((*S).Elements[i] == Elmt)
        {
            found = true;
        }
        i += 1;
    }

    if (!found)
    {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count += 1;
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0;
    
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (S->Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (address i = idx + 1; i < S->Count; i++)
    {
        S->Elements[i - 1] = S->Elements[i];
    }
    S->Count--;
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address idx = 0;
    
    while (!found && idx < S.Count)
    {
        if (S.Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

Set SetUnion(Set s1, Set s2)
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]
{
	Set Union;
	CreateEmpty(&Union);
	
	int i;
	
	for (i = 0; i < s1.Count; i++)
	{
		Insert(&Union, s1.Elements[i]);
	}		
	
	for (i = 0; i < s2.Count; i++)
	{
		Insert(&Union, s2.Elements[i]);
	}
	
	return Union;
}

Set SetIntersection(Set s1, Set s2)
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]
{
	Set Intersect;
	CreateEmpty(&Intersect);
	
	int i;
	
	for (i = 0; i < s1.Count; i++)
	{
		if (IsMember(s2, s1.Elements[i]))
		{
			Insert(&Intersect, s1.Elements[i]);
		}
	}
	
	return Intersect;
}

Set SetSymmetricDifference(Set s1, Set s2)
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]
{
	Set Setdiff;
	CreateEmpty(&Setdiff);
	int i;

	for (i = 0; i < s1.Count; i++)
	{
		if (!IsMember(s2, s1.Elements[i]))
		{
			Insert(&Setdiff, s1.Elements[i]);
		}
	}
	
	for (i = 0; i < s2.Count; i++)
	{
		if (!IsMember(s1, s2.Elements[i]))
		{
			Insert(&Setdiff, s2.Elements[i]);
		}
	}

	return Setdiff;
}

Set SetSubtract(Set s1, Set s2)
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]
{
	Set Substract;
	CreateEmpty(&Substract);
	int i;
	
	for (i = 0; i < s1.Count; i++)
	{
		if (!IsMember(s2, s1.Elements[i]))
		{
			Insert(&Substract, s1.Elements[i]);
		}
	}
	
	return Substract;
}
