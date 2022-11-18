// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 17 Oktober 2022
// Topik praktikum  : Praktikum 6 - Queue
// Deskripsi        : Program yang membuat implementasi dari tanpaBomb.h

#include <stdio.h>
#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb)
{
	if (isEmpty(queue))
	{
		return queue;
	} else
	{
		int i = 0;
		if (IDX_TAIL(queue) < IDX_HEAD(queue))
		{
			for (i = IDX_HEAD(queue); i < CAPACITY - 1; i++)
			{
				if (queue.buffer[i] = bomb)
				{
					queue.buffer[i] = queue.buffer[i+1];
				}
			}
			
			ElType temp = queue.buffer[0];
			
			for (i = 0; i <= IDX_TAIL(queue); i++)
			{
				if (queue.buffer[i] = bomb)
				{
					queue.buffer[i] = queue.buffer[i+1];
				}
			}
			
			if (queue.buffer[CAPACITY - 1] = bomb)
			{
				queue.buffer[CAPACITY - 1] = temp;
			}
		} else
		{
			for (i = IDX_HEAD(queue); i <= IDX_TAIL(queue); i++)
			{
				if (queue.buffer[i] = bomb)
				{
					queue.buffer[i] = queue.buffer[i+1];
				}
			}
		}
		
		return queue;
	}
}
