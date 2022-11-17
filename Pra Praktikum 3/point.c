// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 18 September 2022
// Topik praktikum  : Pra-Praktikum 2 - ADT, Pointer dan Array Dinamik
// Deskripsi        : Program yang membuat implementasi dari point.h

#include <stdio.h>
#include "point.h"
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT p;
    Absis(p) = X;
    Ordinat(p) = Y;
    return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
{
    float x, y;
    scanf("%f", &x);
    scanf("%f", &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat (P2));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X (y = 0)*/
{
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y (x = 0)*/
{
    return (Absis(P) == 0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
{
    if (Absis(P) > 0)
    {
        if (Ordinat(P) > 0) { return 1; }
        else if (Ordinat(P) < 0) { return 4; }
    }
    else if (Absis(P) < 0)
    {
        if (Ordinat(P) > 0) { return 2; }
        else if (Ordinat(P) < 0) { return 3; }
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
{
    return sqrt((Absis(P1) - Absis(P2))*(Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2))*(Ordinat(P1) - Ordinat(P2)));
}