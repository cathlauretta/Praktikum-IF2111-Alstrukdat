/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 4 September 2022
   Topik praktikum  : Pra-Praktikum 1 - Pengenalan C
   Deskripsi        : Program yang mengimplementasikan fungsi penjumlahan 2 bilangan bulat */

#include <stdio.h>

int main()
{
    long int total, a, b;
    scanf("%ld", &a);
    scanf("%ld", &b);

    total = a + b ;
    printf("%ld\n", total);
    return 0;
}