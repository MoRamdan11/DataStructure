#include "linkedStack.h"

void CreatoStack(Stack *s)
{
    s->top = nullptr;
}

void push(Stack *s, StackEntery e)
{
    StackNode *pe=new StackNode;
    pe->entery = e;
    pe->next = s->top;
    s->top = pe;
    cout<<"the element is pushed "<<s->top->entery<<endl;
}

void pop(Stack *s, StackEntery *e)
{
    StackNode *pn = s->top;
    s->top = s->top->next;
    *e = pn->entery;
    delete pn;
} 

int StackFull(Stack *s)
{
    return 0;
}

int StackEmpty(Stack *s)
{
    if(s->top==nullptr)
        return 1;
    else 
        return 0;
}

void clearStack(Stack *s)
{
    StackNode *pn = s->top;
    while(pn!=nullptr)
    {
        pn=pn->next;
        delete s->top;
        s->top = pn;
    }
}

int StackSize(Stack *s)
{
    int count = 0;
    StackNode *pn = s->top;
    while(pn != nullptr)
    {
        pn=pn->next;
        count++;
    }
    return count;
}

void StackTop(Stack *s, StackEntery *e)
{
    *e=s->top->entery;
}

void Stack1st_elem(Stack *s, StackEntery *e)
{
    StackNode *pn = s->top->next;
    StackNode *pe = s->top;
    while(pn!=nullptr)
    {
        pe=pn;
        pn = pn->next;
    }
    *e = pe->entery;
}

void CopyStack(Stack*s1, Stack *s2)
{
    s2->top=s1->top;
}
