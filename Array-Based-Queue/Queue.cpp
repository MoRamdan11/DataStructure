#include "Queue.h"

void CreateQueue(Queue *q)
{
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

void append(Queue *q, QueueEntery e)
{
    q->rear = (q->rear + 1) % MAXQUEUE;
    q->entry[q->rear] = e;
    q->size++;
}

void serve(Queue *q, QueueEntery *e)
{
    *e = q->entry[q->front];
    q->front = (q->front + 1) % MAXQUEUE;
    q->size--;
}

int QueueFull(Queue *q)
{
    return (q->size == MAXQUEUE);
}

int QueueEmpty(Queue *q)
{
    return (q->size == 0);
}

int QueueSize(Queue *q)
{
    return q->size;
}

void ClearQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void TraverseQueue(Queue *q, void (*pf)(QueueEntery))
{
    int s= 0;
    int pos = q->front;
    for(; s<q->size; s++)
    {
        (*pf)(q->entry[pos]);
        pos = (pos+1) % MAXQUEUE;
    }
}
