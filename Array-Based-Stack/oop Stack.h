#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>
#define ListEntery int
#define nullptr NULL
#define StackEntery int
#define MAXSTACK 100
using namespace std;

class Stack//Array Based implementation
{
private:
    StackEntery arr[MAXSTACK];
    int size;
public:
    Stack();
    int StackSize();
    bool StackEmpty();
    bool StackFull();
    void push(StackEntery e);
    void pop();
    bool is_equal(Stack *s);
};
#endif // LIST_H_INCLUDED


