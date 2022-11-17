/* 	NIM 			: 18221157
    Nama			: Cathleen Lauretta
    Tanggal 		: 12 September 2022
    Topik praktikum : Praktikum 2 - Pengenalan C
    Deskripsi 		: Program yang menentukan apakah suatu bilangan merupakan bilangan cantik atau bukan */

#include <stdio.h>

int main()
{
	int N, i, j, bilangan, total = 0, isSeven = 0;
	scanf("%d", &N);
	
	// Melakukan looping sesuai jumlah test case yang diberikan
	for (i = 0; i < N; i++)
	{
		scanf("%d", &bilangan);

		// Melakukan looping dari 1 sampai bilangan yang diberikan dan memeriksa bilangan tersebut apakah merupakan bilangan cantik atau bukan
		for (j = 1; j <= bilangan; j++)
		{
			// Jika bilangan habis dibagi 7, maka bilangan tersebut merupakan bilangan cantik
			if (j % 7 == 0)
			{
				total += j;
			}
			else
			{
				int temp = j;
				do
				// Melakukan pengecekan terhadap bilangan, apakah memiliki angka 7 atau tidak
				{
					if (temp % 10 == 7)
					{
						isSeven = 1;
					}
					temp /= 10;
				} while (temp != 0 && isSeven == 0);

				if (isSeven == 1)
				{
					total += j;
					isSeven = 0;
				}
			}
			// printf("%d\n", total);
			// total = 0;
		}
		printf("%d\n", total);
		total = 0;
	}
	return 0;
}