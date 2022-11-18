// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 26 September 2022
// Topik praktikum  : Praktikum 4 - Array dan ADT List
// Deskripsi        : Program yang membuat implementasi dari arrayMhs.h

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    // Inisiasi array sebesar N untuk menyimpan bilangan
    int arr[N];
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int q;
    scanf("%d", &q);

    // Inisiasi array untuk menyimpan nilai rentang left dan right
    int l[q], r[q];
    for (int i = 1; i <= q; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        int sum = 0;
        // Melakukan looping untuk nilai rentang ke-i
        for (int j = l[i]; j <= r[i]; j++)
        {   
            // Nilai rentang harus di modulo N karena di awal tadi, array hanya diinisiasi sebesar N sehingga nilai rentang tidak bisa lebih dari N
            if (j % N == 0)
            {
                sum += arr[N];
            } else
            {
                sum += arr[j % N];
            }
        }
        printf("%d\n", sum);
    }
}