#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <string>
#define nullptr NULL
#define QueueEntery int
using namespace std;

struct QueueNode
{
    QueueEntery entry;
    QueueNode *next;
};

struct Queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
};

void createQueue(Queue *q);
int QueueEmpty(Queue *q);
int QueueFull(Queue *q);
void append(Queue *q, QueueEntery e);
void serve(Queue *q, QueueEntery *e);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q,void(*df)(QueueEntery));

#endif // LIST_H_INCLUDED

