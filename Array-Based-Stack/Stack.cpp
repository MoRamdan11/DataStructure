#include "stack.h"

void CreateStack(Stack *s)
{
    s->top = 0;
}

void push(Stack *s, StackEntry e)
{
    s->entery[s->top++] = e;   
}

int StackFull(Stack *s)
{
    if(s->top >= MAXSTACK)
        return 1;
    else 
        return 0;
}

void pop(Stack *s, StackEntry *e)
{
    *e=s->entery[--s->top];
}

int StackEmpty(Stack *s)
{
    if(s->top == 0)
        return 1;
    else
        return 0;
}

void clearStack(Stack *s )
{
    s->top = 0;
}

int stackSize(Stack *s)
{
    return s->top;
}

void stackTop(Stack *s, StackEntry *e)
{
    *e = s->entery[s->top-1];
}

void TraverseStack(Stack *s, void (*pf) (StackEntry ) )
{
    int i = s->top;
    for(i; i>0; i--)
    {
        (*pf)(s->entery[i-1]);
    }
}
