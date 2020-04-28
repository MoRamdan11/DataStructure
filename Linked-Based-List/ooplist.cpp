#include "list.h"
#include <algorithm>
ListNode::ListNode(int d)
{
    data = d;
}
void ListNode::set_data(int d)
{
    data = d;
}
ListEntery ListNode::get_data()
{
    return data;
}
void ListNode::set_next(ListNode *x)
{
    next = x;
}
ListNode* ListNode::get_next()
{
    return next;
}


List::List()
{
    head = nullptr;
    size = 0;
}
int List::ListSize()
{
    return size;
}
bool List::ListFull()
{
    return 0;
}
bool List::ListEmpty()
{
    return size == 0;
}
void List::Insert(int p, ListEntery e)
{
    ListNode *pe =new ListNode(e);
    ListNode *q = head;
    if(p == 0)
    {
        pe->next = head;
        head = pe;
    }
    else
    {
        for(int i=0; i<p-1; i++)
        {
            q = q->next;
        }
        pe->next = q->next;
        q->next = pe;
    }
    size++;
}
void List::push_front(ListEntery e)
{
    ListNode *pe = new ListNode(e);
    pe->next = head;
    head = pe;
    size++;
}
void List::pop_front()
{
    if(ListEmpty())
    {
        return;
    }
    ListNode *q = head;
    head = head->next;
    delete q;
}
void List::push_back(ListEntery e)
{
    ListNode *pe = new ListNode(e);
    ListNode *q = head;
    if(head == nullptr)
    {
        pe->next = head;
        head = pe;
        return;
    }
    while(q->next != nullptr)
        q = q->next;
    pe->next = q->next;
    q->next = pe;
}
void List::pop_back()
{
    if(ListEmpty())
        return;
    ListNode *lastnode = head;
    ListNode *q = nullptr;
    while(lastnode->next != nullptr)
    {
        q = lastnode;
        lastnode = lastnode->next;
    }
    delete lastnode;
    if(q !=nullptr)
        q->next = nullptr;
    else
        head = nullptr;
    size--;
}
void List::clear()
{
    while(head != nullptr)
        pop_front();
    size = 0;
}
void List::PrintNode(ListNode *n)
{
    if(n == nullptr)
        return;
    while(n != nullptr)
    {
        cout << n->data << endl;
        n = n->next;
    }
}
/*void List::printtnode(ListNode *n)
{
    if(n == nullptr)
        return;
    cout << n->data << endl;
    return printtnode(n->next);
}*/
bool List::contains(ListEntery d)
{
    ListNode *q = head;
    while(q != nullptr)
    {
        if(q->data == d)
            return true;
        q = q->next;
    }
    return false;
}
void List::remove_element(int pos)
{
    if(ListEmpty())
        return;
    ListNode *q = head;
    if(pos == 0)
    {
        head = q->next;
        delete q;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
            q = q->next;
        ListNode *temp = q->next;
        q->next = temp->next;
        delete temp;
    }
    size--;
}

void List::Bubble_sort()
{
    if(ListEmpty())
        return;
    ListNode *q = head;
    ListNode *lastnode = head->next;
    for(int i=0; i<size; i++)
    {
        bool sorted = false;
        while(lastnode != nullptr)
        {
            if(q->data > lastnode->data)
            {
                swap(q->data, lastnode->data);
                sorted = true;
            }
            q = lastnode;
            lastnode = lastnode->next;
        }
        if(sorted == false)
            return;
    }
}

void List::printlist()
{
    if(ListEmpty())
    {
        cout<<"the list is empty\n";
        return;
    }
    ListNode *q = head;
    while(q != nullptr)
    {
        cout<< q->data <<endl;
        q = q->next;
    }
}
