#include "list.h"

void CreateList(List *s)
{
    s->head = nullptr;
    s->size = 0;
    s->current = nullptr;
    s->currentpos = 0;
}

bool ListFull(List *s)
{
    return 0;
}

bool ListEmpty(List *s)
{
    return s->head == 0;
}

int ListSize(List *s)
{
    return s->size;
}

void DestroyList(List *s)
{
    ListNode *pl;
    pl = s->head;
    for(int i=0; i<s->size; i++)
    {
        pl = pl->next;
        delete s->head;
        s->head = pl;
    }
    s->size = 0;
}

void Insert(int p, ListEntery e, List *s)
{
    ListNode *pe = new ListNode;
    pe->entry = e;
    if(p == 0)
    {
        pe->next = s->head;
        s->head = pe;
        s->current = s->head;
        s->currentpos = 0;
    }
    else
    {
        if(p <= s->currentpos)//before current position
        {
            s->current = s->head;
            s->currentpos = 0;
        }
        for(int i = s->currentpos; i<p-1; i++)
            s->current = s->current->next;
        pe->next = s->current->next;
        s->current->next = pe;
        s->current = pe;
        s->currentpos = p;
    }
    s->size++;
}

void remove(int p, ListEntery *e, List *s)
{
    if(p == 0)
    {
        *e = s->head->entry;
        s->current = s->head->next;
        delete s->head;
        s->head = s->current;
        s->currentpos = 0;
    }
    else
    {
        if(p <= s->currentpos)
        {
            s->current = s->head;
            s->currentpos = 0;
        }
        for(int i = s->currentpos; i<p-1; i++)
            s->current = s->current->next;
        *e = s->current->next->entry;
        ListNode *temp = s->current->next->next;
        delete s->current->next;
        s->current->next = temp;
        s->currentpos = p;
    }
    s->size--;
}

void reterive(int p, ListEntery *e, List *s)
{
    if(p <=  s->currentpos)
        {
            s->current = s->head;
            s->currentpos = 0;
        }
    for(int i=s->currentpos; i<p; i++)
        s->current =s->current->next;
    *e = s->current->entry;
    s->currentpos =p;
}

void replace(int p, ListEntery e, List *s)
{
    if(p <= s->currentpos)
        {
            s->current = s->head;
            s->currentpos = 0;
        }
    for(int i=s->currentpos; i<p; i++)
        s->current = s->current->next;
    s->current->entry = e;
    s->currentpos = p;
}

int LinearSearch(ListEntery e, List *s)
{
    ListNode*q = s->head;
    for(int i = 0; i<s->size; i++)
    {
        if(e == q->entry)
            return i;
        q = q->next;
    }
    return -1;
}

void InsertOrder(ListEntery e, List *s)
{
    ListNode *pe = new ListNode;
    if(s->size == 0)
    {
        pe->next = s->head;
        s->head = pe;
        return;
    }
    ListNode *q = s->head;
    pe->entry = e;
    while(q->next->entry <= e || q->next->next == nullptr)
    {
        q = q->next;
    }
    pe->next = q->next;
    q->next = pe;
}
