// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 18 September 2022
// Topik praktikum  : Pra-Praktikum 3 - ADT, Pointer dan Array Dinamik
// Deskripsi        : Program yang membuat implementasi dari arraydin.h

#include <stdio.h>
#include "arraydin.h"
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
    ArrayDin arr;
    arr.A = (ElType *) malloc (InitialSize * sizeof(ElType));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
    free((*array).A);
}
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
    return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
    return (array.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
    return (array.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    for (int j = Length(*array); i < j; j--)
    {
        (*array).A[j] = (*array).A[j-1]; 
    }
    (*array).A[i] = el;
    (*array).Neff += 1;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    for (i = i; i < Length(*array); i++)
    {
        (*array).A[i] = (*array).A[i+1];    
    }
    (*array).Neff -= 1;
}