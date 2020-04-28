#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <string>
#define ListEntery int
#define nullptr NULL
using namespace std;

class ListNode
{
private:
    ListEntery data;
    ListNode *next;
public:
    ListNode(ListEntery d);
    void set_data(ListEntery d);
    ListEntery get_data();
    void set_next(ListNode *x);
    ListNode* get_next();
    friend class List;
};

class List
{
private:
    int size;
    ListNode *head;
public:
    List();
    ~List(){head = nullptr;}
    int  ListSize();
    bool ListFull();
    bool ListEmpty();
    void Insert(int p, ListEntery e);
    void push_front(ListEntery e);
    void pop_front();
    void push_back(ListEntery e);
    void pop_back();
    void clear();
    void PrintNode(ListNode *n);
    bool contains(ListEntery d);
    void remove_element(int pos);
    void Bubble_sort();
    void printlist();
};


#endif // LIST_H_INCLUDED
