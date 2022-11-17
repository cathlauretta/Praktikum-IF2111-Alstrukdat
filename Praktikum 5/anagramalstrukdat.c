// NIM 				: 18221157
// Nama 			: Cathleen Lauretta
// Tanggal 			: 3 Oktober 2022
// Topik praktikum 	: Mesin Kata
// Deskripsi 		: Program yang membuat implementasi dari anagramalstrukdat.h

#include <stdio.h>
#include "anagramalstrukdat.h"

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string)
{
	int len = 0;
	while (string[len] != '\0')
	{
		len = len + 1;
	}
	
	return len;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command)
{
	Word kata;
	kata.Length = stringLength(command);

	int i;
	for (i = 0; i < stringLength(command); i++)
	{
		kata.TabWord[i] = command[i];
	}

	return kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2)
{
	if (string1.Length == string2.Length)
	{
		int i = 0;
		int num1[26] = {0}, num2[26] = {0};
		
		while (string1.TabWord[i] != '\0')
		{
			num1[string1.TabWord[i] - 'a'] += 1;
			i += 1;
		}
		
		i = 0;
		while (string2.TabWord[i] != '\0')
		{
			num2[string2.TabWord[i] - 'a'] += 1;
			i += 1;
		}

		for (i = 0; i < 26; i++)
		{
			if (num1[i] != num2[i])
			{
				return 0;
			}
		}

		return 1;
	} else
	{
		return 0;
	}
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek)
{
	Word alstrukdat = toKata("alstrukdat");
	
	int amountAnagram = 0;
	
	STARTWORD();
	
	while (!isEndWord())
	{
		if (isAnagram(alstrukdat, currentWord))
		{
			amountAnagram += 1;
		}
		ADVWORD();
	}
		
	*frek = amountAnagram;
}