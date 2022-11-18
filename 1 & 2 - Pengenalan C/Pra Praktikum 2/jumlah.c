/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 12 September 2022
   Topik praktikum  : Pra-Praktikum 2 - Pengenalan C
   Deskripsi        : Program yang menjumlahkan semua digit bilangan dalam suatu integer */

#include <stdio.h>

int main()
{
   int number, total = 0;
   scanf("%d", &number);

   /* Perhitungan dilakukan jika bilangan lebih besar dari 0 */
   while (number > 0)
   {  
      /* Mengambil digit terakhir dari bilangan */
      int digit = number % 10;

      /* Total dari digit yang sudah ada ditambah dengan digit terakhir */
      total += digit;
      number = number / 10; /* Menghilangkan digit terakhir dari bilangan */
   }

   printf("%d\n", total);
   return 0;
}