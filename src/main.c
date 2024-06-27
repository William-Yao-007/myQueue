#include <stdio.h>
#include "queue.h"



void main(void)
{
    QUEUE_T queue_test;
    char s8buffer[QUEUE_MAX_SIZE+2];
    short i = 0;
    init_queue(&queue_test);

    do {
        if(enqueue(&queue_test, i++) < 0) break;
    }while(1);
    printf("FRONT: %d, REAR: %d, SIZE: %d\n", queue_test.front, queue_test.rear, queue_test.size);

    i = 0;
    do {
        if(dequeue(&queue_test, &s8buffer[i++]) < 0) break;
    }while(1);
    printf("FRONT: %d, REAR: %d, SIZE: %d\n", queue_test.front, queue_test.rear, queue_test.size);

    while(1);
}
