// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 25 September 2022
// Topik praktikum  : Pra-Praktikum 4 - Array dan ADT List
// Deskripsi        : Program yang membuat implementasi dari fibonacci.h

#include <stdio.h>
#include "fibonacci.h"

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result)
{
    if (n == 0 || n == 1)
    {
        *result = 1;
    } else
    {
        int num1, num2, nextNum;

        num1 = 1;
        num2 = 1;
        nextNum = 1;

        for (int i = 2; i <= n; i++)
        {
            num1 = num2;
            num2 = nextNum;
            nextNum = num1 + num2;
        }
        *result = nextNum;
    }
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    } else
    {
        int num1, num2, nextNum;

        num1 = 1;
        num2 = 1;
        nextNum = 1;

        for (int i = 2; i <= n; i++)
        {
            num1 = num2;
            num2 = nextNum;
            nextNum = num1 + num2;
        }
        return nextNum;
    }
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result)
{
    result[0] = 1;
    result[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
}