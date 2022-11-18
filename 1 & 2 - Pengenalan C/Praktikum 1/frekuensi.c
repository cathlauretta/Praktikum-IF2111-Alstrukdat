/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 5 September 2022
   Topik praktikum  : Praktikum 1 - Pengenalan C
   Deskripsi        : Program yang menentukan banyaknya frekuensi angka 0-9 dalam suatu string */

#include <stdio.h>
#include <string.h>

int main()
{
    char string[10];
    scanf("%s", &string);

    int count[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        if ((int)(string[i]) == 48) { count[0] += 1; }
        if ((int)(string[i]) == 49) { count[1] += 1; }
        if ((int)(string[i]) == 50) { count[2] += 1; }
        if ((int)(string[i]) == 51) { count[3] += 1; }
        if ((int)(string[i]) == 52) { count[4] += 1; }
        if ((int)(string[i]) == 53) { count[5] += 1; }
        if ((int)(string[i]) == 54) { count[6] += 1; }
        if ((int)(string[i]) == 55) { count[7] += 1; }
        if ((int)(string[i]) == 56) { count[8] += 1; }
        if ((int)(string[i]) == 57) { count[9] += 1; }
    }

    for (int i = 0; i <= 9; i++)
    {
        printf("%d", count[i]);
    }
    printf("\n");
    return 0;
}