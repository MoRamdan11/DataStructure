#include "oop Stack.h"

Stack::Stack()
{
    size = 0;
}
int Stack::StackSize()
{
    return size;
}
bool Stack::StackEmpty()
{
    return size == 0;
}
bool Stack::StackFull()
{
    return size == MAXSTACK;
}

void Stack::push(StackEntery e)
{
    arr[size] = e;
    size ++;
}

void Stack::pop()
{
    size--;
}


bool Stack::is_equal(Stack *s)
{
    Stack c;
    if(this->size != s->size)
        return false;
    if(this->StackEmpty() || s->StackEmpty())
        return false;
    while(!this->StackEmpty())
    {
        if(s->arr[size-1] != this->arr[size-1])
        {
            while(!c.StackEmpty())
            {
                s->push(c.arr[size-1]);
                this->push(c.arr[size-1]);
                c.pop();
            }
            return false;
        }
        else
        {
            c.push(s->arr[size-1]);
            s->pop();
            this->pop();
        }
    }
    return true;
}
