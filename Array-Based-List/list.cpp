#include "list.h"

void CreateList(List *s)
{
    s->size = 0;
}

bool ListFull(List *s)
{
    return (s->size == maxlist) ;
}

bool ListEmpty(List *s)
{
    return s->size == 0;
}

int ListSize(List *s)
{
    return s->size;
}

void DestroyList(List *s)
{
    s->size = 0;
}

void Insert(int p, ListEntery e, List *s)
{
    for(int i = s->size; i>p; i--)
    {
        s->entery[i] = s->entery[i-1];
    }
    s->entery[p] = e;
    s->size ++;
}

void remove(int p, ListEntery *e, List *s)
{
    *e = s->entery[p] ;
    for(int i=p; i<s->size; i++)
    {
        s->entery[i] = s->entery[i+1] ;
    }
}

void traverse(List *s,void (*def)(ListEntery))
{
    for(int i=0; i<s->size; i++)
    {
        (*def)(s->entery[i]);
    }
}

void reterive(int p, ListEntery *e, List *s)
{
    *e = s->entery[p];
}

void replace(int p, ListEntery e, List *s)
{
    s->entery[p] = e;
}

int Rec_BinarySearch(ListEntery e, List*s, int l, int r)//vailed only for array based implementation
{
    if(r < l)
        return -1;
    if(l == r)
    {
        if(s->entery[l] == e)
            return l;
        return -1;
    }
    int mid = (l+r)/2;
    if(s->entery[mid] == e)
        return mid;
    if(e < s->entery[mid])
        return Rec_BinarySearch(e, s, l, mid-1);
    return Rec_BinarySearch(e, s, mid+1, r);
    return -1;
}

int it_BinarySearch(ListEntery e, List *s, int l, int r)//iterative search
{
    if(l > r)
        return -1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(s->entery[mid] == e)
            return mid;
        if(e < s->entery[mid])
        {
            r = mid -1;
            continue;
        }
        l = mid + 1;
    }
    return -1;
}

int Rec_BinarySearch(ListEntery e, List *s)
{
    return Rec_BinarySearch(e, s, 0, s->size-1);
}

int It_BinarySearch(ListEntery e, List *s)
{
    return it_BinarySearch(e, s, 0, s->size-1);
}
