/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 12 September 2022
   Topik praktikum  : Pra-Praktikum 2 - Pengenalan C
   Deskripsi        : Program yang mencetak sebuah persegi berdasarkan masukkan n, dimana panjang dari sisi persegi adalah 2n-1 dan dibentuk dengan pola O dan X secara selang-seling */

#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);

    n = 2*n - 1;

    /* Melakukan looping untuk barisan */
    for (i = 1; i <= n; i++)
    {   /* Melakukan looping untuk kolom */
        for (j = 1; j <= n; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0) /* Jika barisan dan kolom genap, maka pola yang dicetak adalah O */
                {
                    printf("O");
                } else /* Jika barisan genap dan kolom ganjil, maka pola yang dicetak adalah X */
                {
                    printf("X");
                }
            }
            else
            {
                if (j % 2 == 0) /* Jika barisan ganjil dan kolom genap, maka pola yang dicetak adalah X */
                {
                    printf("X");
                } else /* Jika barisan dan kolom ganjil, maka pola yang dicetak adalah O */
                {
                    printf("O");
                }
            }
        }
        printf("\n");
    }
    return 0;
}