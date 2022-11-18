// NIM              : 18221157
// Nama             : Cathleen Lauretta
// Tanggal          : 17 Oktober 2022
// Topik praktikum  : Praktikum 6 - Queue
// Deskripsi        : Program yang membantu Ibu Gra dalam menyelesaikan permasalahannya

#include <stdio.h>
#include "queue.h"

int main()
{
    Queue que_time;
    CreateQueue(&que_time);

    int command, input_time, output_time, min_time, max_time;
    int count = 0;

    scanf("%d", &command);

    while (command != 0)
    {
        if (command == 1 && !isFull(que_time)) // menerima order
        {
            scanf("%d", &input_time);
            
            if (input_time > 0) // time yang valid
            {
                enqueue(&que_time, input_time);
            }
        }
        
        else if (command == 2 && !isEmpty(que_time)) // menyajikan order
        {
            dequeue(&que_time, &output_time);

            count += 1;

            if (count == 1)
            {
                min_time = output_time;
                max_time = output_time;
            } else
            {
                if (output_time < min_time)
                {
                    min_time = output_time;
                } else if (output_time > max_time)
                {
                    max_time = output_time;
                }
            }
        }

        scanf("%d", &command);
    }
    
    printf("%d\n", count);
    printf("%d\n", min_time);
    printf("%d\n", max_time);
}