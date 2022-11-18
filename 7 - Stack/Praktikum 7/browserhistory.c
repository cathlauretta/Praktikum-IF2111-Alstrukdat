// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 24 Oktober 2022
// Topik praktikum  : Praktikum 7 - Stack
// Deskripsi        : Program yang membuat implementasi dari browserhistory.h

#include <stdio.h>
#include <stdlib.h>
#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url)
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */
{
	Push(openedTab, url);
	Top(*history) = Nil;
}

char *currentUrl(Stack *openedTab)
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */
{
	return InfoTop(*openedTab);
}

char *browserHistoryBack(Stack *openedTab, Stack *history, int steps)
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang sebanyak steps
 */
{
	char *url;
		
	for (int i = 1; i <= steps; i++)
	{
		Pop(openedTab, &url);
		Push(history, url);
	}
	
	return InfoTop(*openedTab);
}

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps)
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah sebanyak steps
 */
{
	char *url;
		
	for (int i = 1; i <= steps; i++)
	{
		Pop(history, &url);
		Push(openedTab, url);
	}
	
	return InfoTop(*openedTab);
}

void browserHistoryFree(Stack *history)
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */
{
	Top(*history) = Nil;
}