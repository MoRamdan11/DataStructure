#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#define ListEntery int
#define maxlist 55
#define nullptr NULL
using namespace std;

struct ListNode
{
    ListEntery entry;
    ListNode *next;
};

struct List
{
    ListNode *head;
    ListNode *current;
    int size;
    int currentpos;
};

void CreateList(List *s);
bool ListFull (List *s);
bool ListEmpty(List *s);
int ListSize(List *s);
void DestroyList(List *s);
void Insert(int p, ListEntery e, List *s);
void remove(int p, ListEntery *e, List *s);
void reterive(int p, ListEntery *e, List *s);
void replace(int p, ListEntery e, List *s);
int LinearSearch(ListEntery e, List *s);
void InsertOrder(ListEntery e, List *s);

#endif // LIST_H_INCLUDED
