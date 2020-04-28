#include <iostream>
#define StackEntry int 
#define MAXSTACK 10
using namespace std;

struct Stack
{
    int top;
    StackEntry entery[MAXSTACK];
};

void CreateStack(Stack *s);
void push(Stack *s, StackEntry e);
int StackFull(Stack *s);
void pop(Stack *s, StackEntry *e);
int StackEmpty(Stack *s);
void clearStack(Stack *s );
int stackSize(Stack *s);
void stackTop(Stack *s, StackEntry *e);
void TraverseStack(Stack *s, void (*pf) (StackEntry ) );
