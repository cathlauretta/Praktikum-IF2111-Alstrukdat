// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 12 November 2022
// Topik praktikum  : Pra-Praktikum 10 - Variasi List Linier
// Deskripsi        : Program yang dapat mengetahui elemen ke-N dari sebuah list menggunakan sebuah fungsi perantara ElemenKeN.

#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r)
{
    address p = First(L);
    int nbelmt = 0;

    do
    {
        nbelmt += 1;
        p = Next(p);
    } while (p != First(L));
    // printf("Banyak elemen : %d\n", nbelmt);

    int index = r % nbelmt;
    // printf("indeks ke-%d\n", index);

    address adr = First(L);
    for (int i = 0; i < index; i++)
    {
        adr = Next(adr);
    }

    return Info(adr);
}

int main ()
{
    List L;
    CreateEmpty(&L);

    int input;
    scanf("%d", &input);

    while (input != 0)
    {
        InsVLast(&L, input);
        scanf("%d", &input);
    }

    // PrintInfo(L); printf("\n");

    int r;
    scanf("%d", &r);

    if (IsEmpty(L))
    {
        printf("List Kosong\n");
    } else
    {
        printf("%d\n", ElemenKeN(L, r));
    }

    return 0;
}