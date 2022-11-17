// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 6 November 2022
// Topik praktikum  : Pra-Praktikum 9 - Struktur Berkait
// Deskripsi        : Program yang mengelola statistik daftar nilai sebuah mata kuliah

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    List daftarnilai, inverse_daftarnilai;
    CreateEmpty(&daftarnilai);
    CreateEmpty(&inverse_daftarnilai);

    int nilai;
    scanf("%d", &nilai);

    while (nilai >= 0 && nilai <= 100)
    {
        InsVLast(&daftarnilai, nilai);
        scanf("%d", &nilai);
    }

    if (IsEmpty(daftarnilai))
    {
        printf("Daftar nilai kosong\n");
    } else
    {
        printf("%d\n", NbElmt(daftarnilai));
        printf("%d\n", Max(daftarnilai));
        printf("%d\n", Min(daftarnilai));
        printf("%.2f\n", Average(daftarnilai));
        PrintInfo(daftarnilai); printf("\n");
        InversList(&daftarnilai);
        PrintInfo(daftarnilai); printf("\n");
    }

    return 0;
}