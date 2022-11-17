// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 1 Oktober 2022
// Topik praktikum  : Pra-Praktikum 5 - Mesin Karakter
// Deskripsi        : Fungsi yang dapat menghitung jumlah kemunculan karakter pada suatu pita karakter

#include <stdio.h>
#include "mesinkarakter.h"

int hitungkarakter(char karakter)
{
    int count = 0;

    START();
    while (!IsEOP())
    {
        if (GetCC() == karakter)
        {
            count += 1;
        }
        ADV();
    }

    return count;
}