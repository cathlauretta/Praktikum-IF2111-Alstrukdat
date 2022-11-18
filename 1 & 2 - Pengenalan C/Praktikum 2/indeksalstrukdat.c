/* 	NIM 			: 18221157
    Nama			: Cathleen Lauretta
    Tanggal 		: 12 September 2022
    Topik praktikum : Praktikum 2 - Pengenalan C
    Deskripsi 		: Program yang menghitung jumlah mahasiswa yang lulus, indeks rata-rata, dan indeks akhir dari kelas alstrukdat */

#include <stdio.h>
#include <string.h>

int main()
{
	float nilai;
	scanf("%f", &nilai);

	// Deklarasi variabel 
	int jumlah_lulus = 0, jumlah_mahasiswa = 0;
	float sum = 0;
	float avg;
	char indeks_akhir[1];

	// Ketika nilai tidak sama dengan mark (-999), maka program akan terus menerima input nilai mahasiswa
	while (nilai != -999)
	{
		// Jika nilai mahasiswa di atas indeks B (3), maka mahasiswa tersebut lulus
		if (nilai >= 3 && nilai <= 4)
		{
			jumlah_mahasiswa += 1;
			jumlah_lulus += 1;
			sum += nilai;
		}
		// Jika nilai mahasiswa di bawah indeks B, maka mahasiswa tersebut tidak lulus
		if (nilai >= 0 && nilai < 3)
		{
			jumlah_mahasiswa += 1;
			sum += nilai;
		}
		// Tidak ada else, yang berarti jika ada nilai di luar range 0-4 maka nilai tersebut tidak akan diproses
		scanf("%f", &nilai);
	}

	// Jika nilai yang diinput langsung bernilai mark (-999), maka total nilai dan jumlah mahasiswa sama dengan 0 sehingga tidak ada data yang diinput
	if (sum == 0 && jumlah_mahasiswa == 0)
	{
		printf("Tidak ada data\n");
	} else
	{
		// Menghitung rata-rata nilai mahasiswa
		avg = sum / jumlah_mahasiswa;

		// Menghitung indeks akhir dari rata-rata nilai mahasiswa
		if (avg == 4) { strcpy(indeks_akhir, "A"); }
		else if (avg >= 3 && avg < 4) { strcpy(indeks_akhir, "B"); }
		else if (avg >= 2 && avg < 3) { strcpy(indeks_akhir, "C"); }
		else if (avg >= 1 && avg < 2) { strcpy(indeks_akhir, "D"); }
		else { strcpy(indeks_akhir, "E"); }

		// Mencetak hasil perhitungan dari data nilai yang didapat
		printf("Jumlah mahasiswa yang lulus = %d\n", jumlah_lulus);
		printf("Nilai rata-rata = %.2f\n", avg);
		printf("Indeks akhir kelas = %s\n", indeks_akhir);
	}

	return 0;
}