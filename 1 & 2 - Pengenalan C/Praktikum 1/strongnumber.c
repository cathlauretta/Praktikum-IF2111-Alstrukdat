/* NIM              : 18221157
   Nama             : Cathleen Lauretta
   Tanggal          : 5 September 2022
   Topik praktikum  : Praktikum 1 - Pengenalan C
   Deskripsi        : Program yang menentukan apakah sebuah bilangan adalah strong number atau bukan */

#include <stdio.h>

int main()
{
    int number, temp, total = 0;
    scanf("%d", &number);

    /* Menyimpan angka pada variabel temporary */
    temp = number;

    while (temp > 0)
    {
        int digit = temp % 10, kali = 1; /* Digit merupakan bilangan terakhir dari angka yang diinput */
        temp = temp / 10; /* temp diubah menjadi angka yang didapat dari sisa pembagian temp dengan 10 */

        if (digit == 0) /* 0! = 1 */
        {
            kali = 1;
        } else
        {
            for (int i = 1; i <= digit; i++)
            {
                kali *= i;
            }
        }
        total += kali;
    }

    if (total == number)
    {
        printf("Y\n");
    } else
    {
        printf("N\n");
    }
}