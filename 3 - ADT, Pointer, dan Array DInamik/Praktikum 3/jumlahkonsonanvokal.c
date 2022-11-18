// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 19 September 2022
// Topik praktikum  : Praktikum 2 - ADT, Pointer dan Array Dinamik
// Deskripsi        : Program yang membuat implementasi dari jumlahkonsonanvokal.h

#include <stdio.h>
#include "jumlahkonsonanvokal.h"

int isAlphabet (char cc)
{
    if ((cc >= 'a' && cc <= 'z') || (cc >= 'A' && cc <= 'Z'))
    {
        return 1;
    } else
    {
        return 0;
    }
}

int isVowel (char cc)
{
    if (cc == 'a' || cc == 'i' || cc == 'u' || cc == 'e' || cc == 'o' || cc == 'A' || cc == 'I' || cc == 'U' || cc == 'E' || cc == 'O')
    {
        return 1;
    } else
    {
        return 0;
    }
}

void jumlahKonsonanVokal(char* string, int* konsonan, int* vokal)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isAlphabet(string[i]))
        {
            if (isVowel(string[i]))
            {
                ++(*vokal);
            } else
            {
                ++(*konsonan);
            }
        }
    }
}