/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 12 September 2022
   Topik praktikum  : Pra-Praktikum 2 - Pengenalan C
   Deskripsi        : Program yang memeriksa apakah kedua buah string memiliki panjang dan huruf yang sama atau tidak */

#include <stdio.h>
#include <string.h>

int main()
{
    char string1[100], string2[100];
    scanf("%s", &string1);
    scanf("%s", &string2);

    /* Deklarasi kondisi. Untuk True maka condition bernilai 1 */
    int condition = 1;
    int i = 0;

    /* Melakukan perbandingan terhadap panjang string */
    if (strlen(string1) == strlen(string2))
    {
        /* Melakukan perbandingan terhadap setiap huruf pada string */
        while (string1[i] != '\0' && condition == 1) 
        {
            if (string1[i] != string2[i])
            {
                /* Jika ada huruf yang tidak sama, maka periksa apakah hurufnya merupakan bentuk kapital dari huruf string lainnya */
                if (string1[i] + 32 != string2[i] && string1[i] != string2[i] + 32) /* Jarak antar huruf kapital ke huruf kecil = 32 */
                {
                    condition = 0;
                }
            }
            i += 1;
        }
    } else
    {
        condition = 0;
    }

    if (condition == 1)
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }
    return 0;
}