#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#define ListEntery int
#define maxlist 100
using namespace std;

struct List
{
    ListEntery entery[maxlist] ;
    int size ;
};

void CreateList(List *s);
bool ListFull (List *s);
bool ListEmpty(List *s);
int ListSize(List *s);
void DestroyList(List *s);
void Insert(int p, ListEntery e, List *s);
void remove(int p, ListEntery *e, List *s);
void traverse(List *s,void (*def)(ListEntery));
void reterive(int p, ListEntery *e, List *s);
void replace(int p, ListEntery e, List *s);
int Rec_BinarySearch(ListEntery e, List *s);
int It_BinarySearch(ListEntery e, List *s);

#endif // LIST_H_INCLUDED
