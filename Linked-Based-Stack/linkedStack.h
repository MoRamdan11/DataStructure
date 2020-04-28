#include <iostream>
#define StackEntery int
using namespace std;

struct StackNode
{
    StackEntery entery;
    StackNode *next;
};

struct Stack
{
    StackNode *top;
};
void CreatStack(Stack *s);
void push(Stack *s, StackEntery e);
void pop(Stack *s, StackEntery *e);
int StackFull(Stack *s);
int StackEmpty(Stack *s);
void clearStack(Stack *s);
int StackSize(Stack *s);
void StackTop(Stack *s, StackEntery *e);
void Stack1st_elem(Stack *s, StackEntery *e);
void CopyStack(Stack*s1, Stack *s2);
