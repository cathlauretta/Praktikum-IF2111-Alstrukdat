// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 6 November 2022
// Topik praktikum  : Pra-Praktikum 9 - Struktur Berkait
// Deskripsi        : Program yang membuat implementasi dari OddEvenList.h

#include <stdio.h>
#include <stdlib.h>
#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even)
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/
{
    CreateEmpty(Odd);
    CreateEmpty(Even);

    address p = First(L);
    address n = Next(p);

    while (p != Nil)
    {
        if (Info(p) % 2 == 0)
        {
            InsVLast(Even, Info(p));
        } else
        {
            InsVLast(Odd, Info(p));
        }

        p = n;
        if (n != Nil)
        {
            n = Next(p);
        }
    }

    // PrintInfo(L); printf("\n");
    // PrintInfo(*Odd); printf("\n");
    // PrintInfo(*Even); printf("\n");

    // Sorting
    if (!IsEmpty(*Odd))
    {
        address o = First(*Odd);
        while (o != Nil)
        {
            address p = First(*Odd);

            while (Next(p) != Nil)
            {
                address q = Next(p);
                
                if (Info(p) > Info(q) && q != Nil)
                {
                    infotype temp = Info(p);
                    Info(p) = Info(q);
                    Info(q) = temp;
                }

                p = Next(p);
            }

            o = Next(o);
        }
    }

    if (!IsEmpty(*Even))
    {
        address e = First(*Even);
        while (e != Nil)
        {
            address p = First(*Even);

            while (Next(p) != Nil)
            {
                address q = Next(p);
                
                if (Info(p) > Info(q) && q != Nil)
                {
                    infotype temp = Info(p);
                    Info(p) = Info(q);
                    Info(q) = temp;
                }

                p = Next(p);
            }

            e = Next(e);
        }
    }

    // printf("Yang sudah terurut\n");
    // PrintInfo(L); printf("\n");
    // PrintInfo(*Odd); printf("\n");
    // PrintInfo(*Even); printf("\n");
}

// int main()
// {
//     List L;
//     CreateEmpty(&L);

//     InsVLast(&L, 14);
//     InsVLast(&L, 17);
//     InsVLast(&L, 32);
//     InsVLast(&L, 8);
//     InsVLast(&L, 7);
//     InsVLast(&L, 29);
//     InsVLast(&L, 20);
//     InsVLast(&L, 33);
//     InsVLast(&L, 25);
//     PrintInfo(L); printf("\n");

//     List Odd, Even;
//     OddEvenList(L, &Odd, &Even);
// }