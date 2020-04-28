#include "Queue.h"

void createQueue(Queue *q)
{
    q->front = nullptr;
    q->rear  = nullptr;
    q->size  = 0;
}

int QueueEmpty(Queue *q)
{
    if(q->front == nullptr && q->rear == nullptr)
        return 1;
    return 0;
}

int QueueFull(Queue *q)
{
    return 0;
}

void append(Queue *q, QueueEntery e)
{
    QueueNode *pe = new QueueNode;
    pe->entry = e;
    pe->next = nullptr;
    if(q->rear == nullptr)
    {
        q->front = pe;
    }
    else
    {
        q->rear->next = pe;
    }
    q->rear = pe;
    q->size++;
}

void serve(Queue *q, QueueEntery *e)
{
    *e = q->front->entry;
    QueueNode *pe = q->front;
    if(q->front->next == nullptr)
    {
        q->front = nullptr;
        q->rear = nullptr;
    }
    else
        q->front = q->front->next;
    delete pe;
    q->size--;
}

int QueueSize(Queue *q)
{
    return q->size;
}

void ClearQueue(Queue *q)
{
    while(q->rear != nullptr)
    {
        q->rear = q->rear->next;
        delete q->front;
        q->front = q->rear;
    }
}

 void TraverseQueue(Queue *q,void(*df)(QueueEntery))
{
    QueueNode *it = q->front;
    while( it )
    {
        (*df)(it->entry);
        it = it->next;
    }
}
