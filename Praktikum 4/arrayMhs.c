// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 26 September 2022
// Topik praktikum  : Praktikum 4 - Array dan ADT List
// Deskripsi        : Program yang membuat implementasi dari arrayMhs.h

#include <stdio.h>
#include "arrayMhs.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMhs *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = 0;
{
    (*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMhs T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabMhs T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx (TabMhs T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return IdxMin;
}

IdxType GetLastIdx (TabMhs T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return T.Neff;
}

ElType GetElmt (TabMhs T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMhs Tin, TabMhs *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	(*Tout).Neff = Tin.Neff;
	for(int i = IdxMin; i <= Tin.Neff; i++)
	{
		(*Tout).TI[i] = Tin.TI[i];
	}
}

void SetEl (TabMhs *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	(*T).TI[i] = v;
	if ((*T).Neff < i)
	{
		(*T).Neff = i;
	}
}
	
void SetNeff (TabMhs *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	(*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMhs T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	if ((i >= IdxMin) && (i <= IdxMax))
	{
		return true;
	} else
	{
		return false;
	}
}

boolean IsIdxEff (TabMhs T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	if ((i >= IdxMin) && (i <= T.Neff)){
		return true;
	} else {
		return false;
	}
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMhs T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return (T.Neff == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabMhs T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
	return (T.Neff == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMhs T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh print tabel
Test | 12321123 | 3.61
Ini Juga Test | 12321124 | 3.21
Test Lagi | 12321125 | 3.11
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    } else
    {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("%s | %s | %.2f\n", T.TI[i].nama, T.TI[i].nim, T.TI[i].nilai);
        }
    }
}

/* ********** KONSTRUKTOR MAHASISWA ********** */
ElType MakeMahasiswa (char* Nama, char* NIM, float Nilai)
/* Membentuk sebuah Mahasiswa dari komponen-komponennya */
/* I.S. Nama, NIM, Nilai terdefinisi */
/* F.S. Mahasiswa M terbentuk dengan Nama, NIM, Nilai yang sesuai */
{
	ElType M;
	
	M.nama = Nama;
	M.nim = NIM;
	M.nilai = Nilai;
	
	return M;
}

/* ********** OPERATOR STATISTIK MAHASISWA ********** */
float RataRata (TabMhs T)
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rata-rata dari elemen tabel */
{
	float sum = 0;
	float count = 0;

	for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		sum += T.TI[i].nilai;
		count += 1;
	}

	return (sum / count);
}

float Max (TabMhs T)
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai maksimum dari elemen tabel */
{
	float max = T.TI[GetFirstIdx(T)].nilai;

	for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
	{
		if (T.TI[i].nilai > max)
		{
			max = T.TI[i].nilai;
		}
	}

	return max;
}

float Min (TabMhs T)
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai minimum dari elemen tabel */
{
	float min = T.TI[GetFirstIdx(T)].nilai;

	for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
	{
		if (T.TI[i].nilai < min)
		{
			min = T.TI[i].nilai;
		}
	}

	return min;
}

char *MaxNama (TabMhs T)
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai tertinggi */
/* Jika ada lebih dari satu mahasiswa dengan nilai tertinggi, maka yang diambil yang nim lebih rendah */
{
	float max = Max(T);
	char *maxNama, *NIM;
	boolean found = false;

	while (!found)
	{
		for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (T.TI[i].nilai == max)
			{
				maxNama = T.TI[i].nama;
				NIM = T.TI[i].nim;
				found = true;
			}
		}
	}
	
	for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		if ((T.TI[i].nilai == max) && (*(T.TI[i].nim) < *NIM))
		{
			maxNama = T.TI[i].nama;
			NIM = T.TI[i].nim;
		}
	}

	return maxNama;
}

char *MinNama (TabMhs T)
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai terendah */
/* Jika ada lebih dari satu mahasiswa dengan nilai terendah, maka yang diambil yang nim lebih rendah */
{
	float min = Min(T);
	char *minNama, *NIM;
	boolean found = false;

	while (!found)
	{
		for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (T.TI[i].nilai == min)
			{
				minNama = T.TI[i].nama;
				NIM = T.TI[i].nim;
				found = true;
			}
		}
	}
	
	for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		if ((T.TI[i].nilai == min) && ((*T.TI[i].nim) < *NIM))
		{
			minNama = T.TI[i].nama;
			NIM = T.TI[i].nim;
		}
	}

	return minNama;
}

int JumlahJurusan (TabMhs T, char* Jurusan)
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan jumlah mahasiswa yang berasal dari jurusan Jurusan, yang berbentuk 3 angka (contoh: 182) */
/* Jika tidak ada mahasiswa yang berasal dari jurusan Jurusan, maka menghasilkan 0 */
{
	int total;

	for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		if ((Jurusan[0] == T.TI[i].nim[0]) && (Jurusan[1] == T.TI[i].nim[1]) && (Jurusan[2] == T.TI[i].nim[2]))
		{
			total += 1;
		}
	}

	return total;
}