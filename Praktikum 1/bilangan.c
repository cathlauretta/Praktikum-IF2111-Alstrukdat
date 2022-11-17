/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 5 September 2022
   Topik praktikum  : Praktikum 1 - Pengenalan C
   Deskripsi        : Program yang menentukan apakah suatu bilangan merupakan bilangan subset genap atau tidak */

#include <stdio.h>

int main()
{
    int bilangan;
    scanf("%d", &bilangan);

    if (bilangan > 2 && bilangan % 2 == 0)
    /* Penjumlahan angka 2 hanya bisa didapat dari 1+1, dimana 1 bukanlah bilangan ganjil sehingga 2 bukan subset genap */
    {
        printf("Ya\n");
    }
    else /* Bilangan yang tidak habis dibagi 2 */
    {
        printf("Tidak\n");
    }

    return 0;
}