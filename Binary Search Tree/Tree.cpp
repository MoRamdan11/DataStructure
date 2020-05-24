#include "Tree.h"
//All function for 2 different structures of tree 
void CreateTree(Tree *t)//Structure 1
{
    *t = nullptr;
}

void CreateTree2(Tree2 *t)//Structure 2 contains root, size, depth
{
    t->root = nullptr;
    t->depth = 0;
    t->size = 0;
}

int TreeEmpty(Tree *t)
{
    return ((*t) == nullptr);
}

int TreeEmpty2(Tree2 *t)
{
    //any one of this 2 lines make the function
    return (t->size == 0);
    //return (t->root == nullptr);
}

int TreeFull(Tree *t)
{
    return 0;
}

int TreeFull2(Tree2 *t)
{
    return 0;
}

void RecInorder(Tree *t, void(*visit)(TreeEntry ) )
{
    if(*t == nullptr)
        return ;
    RecInorder(&(*t)->left, visit) ;
    visit( (*t)->entry ) ;
    RecInorder(&(*t)->right, visit) ;
}

void RecInorder2(Tree2 *t, void (*visit)(TreeEntry) )
{
    RecInorder(&(t->root),visit);
}

void ClearTreeAux(Tree *t)
{
    if(*t == nullptr)
        return;
    ClearTree(&(*t)->left);
    ClearTree(&(*t)->right);
    delete *t;
}

void ClearTree(Tree *t)
{
    ClearTreeAux(&(*t));
    *t = nullptr;
}

void ClearTree2(Tree2 *t)
{
    ClearTreeAux(&t->root);
    t->root = nullptr;
    t->depth = 0;
    t->size = 0;
}

void InsetNode(Tree *t, TreeEntry *e)
{
    if(*t == nullptr)
    {
        (*t) = new TreeNode;
        (*t)->entry = *e;
        (*t)->left = nullptr;
        (*t)->right = nullptr;
    }
    else
        {
            if(*e < (*t)->entry)
                InsetNode(&(*t)->left, e);
            else
                 InsetNode(&(*t)->right, e);
        }
}

void InsertNodeAux(Tree *t, TreeEntry *e, int *pdepth)
{
    if(*t == nullptr)
    {
        (*t) = new TreeNode ;
        (*t)->entry = *e;
        (*t)->left = nullptr;
        (*t)->right = nullptr;
    }
    else
    {
        if(*e < (*t)->entry)
            InsertNodeAux(&(*t)->left, e, pdepth);
        else
            InsertNodeAux(&(*t)->right, e, pdepth);
    }
    (*pdepth)++ ;
}

void InsertNode2(Tree2 *t, TreeEntry *e)
{
    int d = 0;
    InsertNodeAux(&t->root, e, &d);
    if(d > t->depth)
        t->depth = d;
    t->size++;
}

void ItInsertNode(Tree2 *t, TreeEntry *e) //iterative insert func for Tree 2
{
    TreeNode *pe = new TreeNode;
    TreeNode *q = t->root;
    TreeNode *temp = t->root;
    int d = 1;
    pe->entry = *e;
    pe->left = nullptr;
    pe->right = nullptr;
    if(t->root == nullptr)
    {
        t->root = pe;
    }
    else
    {
        while(q)
        {
            temp = q;
            if(*e < q->entry)
                q = q->left;
            else
                q = q->right;
            d++;
        }
        if(*e < temp->entry)
            temp->left = pe;
        else
            temp->right = pe;
    }
    if(d > t->depth)
        t->depth = d;
    t->size++;
}

int TreeSize(Tree *t)
{
    if(*t == nullptr)
        return 0;
    return 1 + TreeSize(&(*t)->left) + TreeSize(&(*t)->right);
}

int TreeSize2(Tree2 *t)
{
    return t->size;
}

int Treedepth(Tree *t)
{
    if(*t == nullptr)
        return 0;
    int m = Treedepth(&(*t)->left);
    int n = Treedepth(&(*t)->right);
    return (m > n)?1 + m : 1 + n ; 
}

int Treedepth2(Tree2 *t)
{
    return t->depth;
}

int RecFind(Tree *t, TreeEntry *e)
{
    if(*t == nullptr)
        return 0;
    if((*t)->entry == *e)
        return 1;
    if(*e < (*t)->entry)
        return RecFind(&(*t)->left, e);
    return RecFind(&(*t)->right, e);
}

int RecFind2(Tree2 *t, TreeEntry *e)
{
    return RecFind(&(t)->root, e);
}

int itFind(Tree *t, TreeEntry *e)
{
    TreeNode *q = *t;
    if(*t == nullptr)
        return 0;
    while(q)
    {
        if((*t)->entry == *e)
            return 1;
        if(*e < q->entry)
            q = q->left;
        else
            q = q->right;
    }
    return 0;
}

int itFind2(Tree2 *t, TreeEntry *e)
{
    TreeNode *q = t->root;
    if(t->root == nullptr)
        return 0;
    while(q)
    {
        if(t->root->entry == *e)
            return 1;
        if(*e < t->root->entry)
            q = q->left;
        else
            q = q->right;
        return 0;
    }
}

void DeleteNode(Tree *pt)
{
    TreeNode *q = *pt;
    TreeNode *r = *pt;
    if(!(*pt)->left)
        (*pt) = (*pt)->right;
    else if(!(*pt)->right)
        (*pt) = (*pt)->left;
    else
    {
        q = (*pt)->left;
        if(!q->right)
        {
            (*pt)->entry = q->entry;
            (*pt)->left = q->left;
        }
        else
        {
            do
            {
                r = q;
                q = q->right;
            }while(q->right);
            (*pt)->entry = q->entry;
            r->right = r=q->left;
            //(*pt)->left = q->left;
        }
    }
    delete q;
}
void Delete(Tree *t, TreeEntry *e)
{
    if(*t == nullptr)
        return ;
    TreeNode *q = *t ;
    while(q)
    {
        if(q->entry == *e)
        {
            DeleteNode(&q);
            return;
        }
        else
        {
            if(*e < q->entry)
                q = q->left;
            else
                q = q->right;
        }
    }
}
void Delete2(Tree2 *t, TreeEntry *e)
{
    RecDelete(&(t->root), e);
    t->size --;
}
