#include <iostream>
#define TreeEntry int
using namespace std;

struct TreeNode
{
    TreeEntry entry;
    TreeNode *left;
    TreeNode *right;
};

typedef TreeNode *Tree;

struct Tree2
{
    int size;
    int depth;
    TreeNode *root;
};

void CreateTree(Tree *t);//Structure 1
void CreateTree2(Tree2 *t);//Structure 2 contains root, size, depth
int TreeEmpty(Tree *t);
int TreeEmpty2(Tree2 *t);
int TreeFull(Tree *t);
int TreeFull2(Tree2 *t);
void RecInorder(Tree *t, void(*visit)(TreeEntry ) );
void RecInorder2(Tree2 *t, void (*visit)(TreeEntry) );
void ClearTreeAux(Tree *t);
void ClearTree(Tree *t);
void ClearTree2(Tree2 *t);
void InsetNode(Tree *t, TreeEntry *e);
void InsertNodeAux(Tree *t, TreeEntry *e, int *pdepth);
void InsertNode2(Tree2 *t, TreeEntry *e);
void ItInsertNode(Tree2 *t, TreeEntry *e); //iterative insert func for Tree 2
int TreeSize(Tree *t);
int TreeSize2(Tree2 *t);
int Treedepth(Tree *t);
int Treedepth2(Tree2 *t);
int RecFind(Tree *t, TreeEntry *e);
int RecFind2(Tree2 *t, TreeEntry *e);
int itFind(Tree *t, TreeEntry *e);
int itFind2(Tree2 *t, TreeEntry *e);
void DeleteNode(TreeNode *q);
void Delete(Tree *t, TreeEntry *e);
void Delete2(Tree2 *t, TreeEntry *e);
