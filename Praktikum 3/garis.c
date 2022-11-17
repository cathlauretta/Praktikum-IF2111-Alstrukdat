// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 19 September 2022
// Topik praktikum  : Praktikum 2 - ADT, Pointer dan Array Dinamik
// Deskripsi        : Program yang membuat implementasi dari garis.h

#include <stdio.h>
#include "garis.h"

/** *** Konstruktor membentuk GARIS *** */
void MakeGARIS(POINT P1, POINT P2, GARIS *L)
/** I.S. P1 dan P2 terdefinisi */
/** F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/** Membentuk sebuah L dari komponen-komponennya */
{
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

/** KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/** ***************************************************************** */
void BacaGARIS(GARIS *L)
/** I.S. sembarang **/
/** F.S. L terdefinisi sebagai GARIS yang valid **/
/** Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat
   membentuk GARIS yang valid
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. **/
/** Jika pembacaan garis tidak valid, diberikan pesan kesalahan:
   "Garis tidak valid" **/
{
	POINT P1, P2;
	
	do {
		BacaPOINT(&P1);
		BacaPOINT(&P2);

		if (EQ(P1, P2))
		{
			printf("Garis tidak valid\n");
		}
	} while (EQ(P1, P2));

	MakeGARIS(P1, P2, L);
}

void TulisGARIS(GARIS L)
/** I.S. L terdefinisi **/
/** F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))"
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter **/
/** Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. **/
{
	printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}

/** *** Kelompok operasi garis *** */
float PanjangGARIS(GARIS L)
/** Menghitung panjang garis L : berikan rumusnya **/
{
	return Panjang(PAwal(L), PAkhir(L));
}
float Gradien(GARIS L)
/** Mengembalikan Gradien (m) dari L **/
/** Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) **/
/** Prekondisi : x1 != x2 **/
{
	float m;
	m = (Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))/(Absis(PAkhir(L)) - Absis(PAwal(L)));
	return m;
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus(GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
	return (Gradien(L1) * Gradien(L2) == (-1));
}
boolean IsSejajar(GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
	return (Gradien(L1) == Gradien(L2));
}
