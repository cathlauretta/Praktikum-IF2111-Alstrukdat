/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 4 September 2022
   Topik praktikum  : Pra-Praktikum 1 - Pengenalan C
   Deskripsi        : Program yang menerima masukkan detik dan mengeluarkan keluaran dalam format jam, menit, dan detik */

#include <stdio.h>

int main()
{
    int inputDetik, jam, menit, detik;
    scanf("%d", &inputDetik);

    jam = ("%d", inputDetik/3600);
    menit = ("%d", (inputDetik%3600)/60);
    detik = ("%d", (inputDetik%3600)%60);

    printf("%d detik = %d jam %d menit %d detik\n", inputDetik, jam, menit, detik);

    return 0;
}