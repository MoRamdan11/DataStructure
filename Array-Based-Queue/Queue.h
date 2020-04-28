#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
#include <string>
#define nullptr NULL
#define QueueEntery int
#define MAXQUEUE 100
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    QueueEntery entry[MAXQUEUE];
};

void CreateQueue(Queue *q);
void append(Queue *q, QueueEntery e);
void serve(Queue *q, QueueEntery *e);
int QueueFull(Queue *q);
int QueueEmpty(Queue *q);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q, void (*pf)(QueueEntery));

#endif // LIST_H_INCLUDED
