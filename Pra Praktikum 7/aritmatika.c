// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 22 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - Stack
// Deskripsi        : Program yang membuat implementasi dari aritmatika.h

#include <stdio.h>
#include "aritmatika.h"

boolean isOperator(char input)
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/
{
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op)
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/
{
    int val = 0;

    if (op == '+')
    {
        val = angka1 + angka2;
    } else if (op == '-')
    {
        val = angka1 - angka2;
    } else if (op == '*')
    {
        val = angka1 * angka2;
    } else if (op == '/')
    {
        val = angka1 / angka2;
    }

    return val;
}

int eval(char *input, int length)
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
{
    int angka1, angka2;
    int perhitungan, to_int;
    Stack container;
    CreateEmpty(&container);

    int count = 0;

    while (count < length)
    {
        if (!isOperator(*input))
        {
            to_int = (int)(*input) - 48; // ASCII char '0' = 48
            Push(&container, to_int);
        } else
        {
            Pop(&container, &angka2);
            Pop(&container, &angka1);
            perhitungan = hitung(angka1, angka2, (*input));

            Push(&container, perhitungan);
        }

        count += 1;
        input += 1;
    }

    Pop(&container, &perhitungan);
    return perhitungan;
}