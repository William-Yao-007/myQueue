#ifndef __QUEUE_H
#define __QUEUE_H


#define QUEUE_MAX_SIZE              20
//=============================================================================
// type
//=============================================================================
typedef struct {
    char data[QUEUE_MAX_SIZE];
    short front;
    short rear;
    short size;
}QUEUE_T;

//=============================================================================
// extern 
//=============================================================================
extern void init_queue(QUEUE_T *qp);
extern char enqueue(QUEUE_T *qp, char data);
extern char dequeue(QUEUE_T *qp, char *data);













#endif


