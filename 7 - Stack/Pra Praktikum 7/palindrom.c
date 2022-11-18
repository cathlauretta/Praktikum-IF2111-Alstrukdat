// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 22 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - Stack
// Deskripsi        : Program yang memeriksa apakah sebuah stack merupakan stack yang palindrom atau tidak.

#include <stdio.h>
#include "stack.h"

int main()
{
    Stack stack;
    CreateEmpty(&stack);

    int angka, ambil;
    int bilangan = 0, bilangan_reversed = 0;
    scanf("%d", &angka);

    if (angka == 0) // Stack tidak berisi apa2
    {
        printf("Stack kosong\n");
    } else // Stack berisi sesuatu
    {
        while (angka != 0)
        {
            Push(&stack, angka);
            bilangan = bilangan * 10 + angka;
            scanf("%d", &angka);
        }
    
        // angka = 0 artinya program berhenti menerima input
        while (Top(stack) != Nil)
        {
            Pop(&stack, &ambil);
            bilangan_reversed = bilangan_reversed * 10 + ambil;
        }

        if (bilangan == bilangan_reversed)
        {
            printf("Palindrom\n");
        } else
        {
            printf("Bukan Palindrom\n");
        }
    }

    return 0;
}