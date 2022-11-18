// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 17 Oktober 2022
// Topik praktikum  : Praktikum 6 - Queue
// Deskripsi        : Program yang membuat implementasi dari copyqueue.h

#include <stdio.h>
#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput)
{	
	if (!isEmpty(*queueInput))
	{	
		int i = IDX_HEAD(*queueInput), tail = IDX_TAIL(*queueInput);
		ElType val;

		while (i != tail)
		{
			dequeue(queueInput, &val);
			enqueue(queueInput, val);
			enqueue(queueOutput, val);
			i = IDX_HEAD(*queueInput);
		}

		dequeue(queueInput, &val);
		enqueue(queueInput, val);
		enqueue(queueOutput, val);
	}
	
	// if (!isEmpty(*queueInput))
	// {
	// 	for (int i = IDX_HEAD(*queueInput); i <= IDX_TAIL(*queueInput); i++)
	// 	{
	// 		(*queueOutput).buffer[i] = (*queueInput).buffer[i];
	// 	}
	// }
}

// int main()
// {
// 	Queue que1, que2;

// 	CreateQueue(&que1);
// 	CreateQueue(&que2);

// 	enqueue(&que1, 3);
// 	enqueue(&que1, 7);
// 	enqueue(&que1, 8);
// 	enqueue(&que1, 2);

// 	displayQueue(que1);
// 	displayQueue(que2);

// 	copyQueue(&que1, &que2);

// 	displayQueue(que1);
// 	displayQueue(que2);	
// }
