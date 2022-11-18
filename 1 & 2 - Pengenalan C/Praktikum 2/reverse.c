/* 	NIM 			: 18221157
    Nama			: Cathleen Lauretta
    Tanggal 		: 12 September 2022
    Topik praktikum : Praktikum 2 - Pengenalan C
    Deskripsi 		: Program yang menerima satu bilangan integer positif dan memberikan output integer tersebut dengan tiap digitnya sudah dibalik */

#include <stdio.h>

int main()
{
	int bilangan, digit, bilangan_reversed = 0;
	scanf("%d", &bilangan);

	/* Perhitungan dilakukan jika bilangan lebih besar dari 0 */
	while (bilangan != 0)
	{
		/* Mengambil digit terakhir dari bilangan */
		digit = bilangan % 10;
		/* Digit yang sudah diambil ditambahkan ke bilangan reversed. Tapi supaya digit bisa ditambahkan ke belakang, maka bilangan yang sebelumnya disimpan harus dikali 10 terlebih dahulu */
		bilangan_reversed = bilangan_reversed * 10 + digit;
		/* Menghapus digit terakhir dari bilangan */
		bilangan = bilangan / 10;
	}

	printf("%d\n", bilangan_reversed);
	return 0;
}