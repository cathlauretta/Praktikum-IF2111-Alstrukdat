// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 18 September 2022
// Topik praktikum  : Pra-Praktikum 3 - ADT, Pointer dan Array Dinamik
// Deskripsi        : Program yang membuat implementasi dari panjangstring.h

#include <stdio.h>
#include "panjangstring.h"

int panjangString(char* string)
{
    int length = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        length += 1;
    }

    return length;
}