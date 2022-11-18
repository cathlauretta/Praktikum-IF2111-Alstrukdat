// NIM 				: 18221157
// Nama 			: Cathleen Lauretta
// Tanggal 			: 3 Oktober 2022
// Topik praktikum 	: Mesin Kata
// Deskripsi 		: Program yang membuat implementasi dari hitungfrekuensi.h

#include <stdio.h>
#include "hitungfrekuensi.h"

int hitungfrekuensi()
{
	int count = 0;
	
	START();
	while (currentChar != MARK)
	{
		if (currentChar == 't' || currentChar == 'T')
		{
			ADV();
			if (currentChar == 'i' || currentChar == 'I')
			{
				ADV();
				if (currentChar == 'g' || currentChar == 'G')
				{
					ADV();
					if (currentChar == 'a' || currentChar == 'A')
					{
						count += 1;
					}
				}
			}
		}
		ADV();
	}
	
	return count;
}
