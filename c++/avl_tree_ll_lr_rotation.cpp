/*
AVL tree (named after Adelson-Velsky and Landis) is a self-balancing binary search tree.  It was the first such data structure if its kind to be
thought up.  In an AVL tree, the heights of two child subtrees of any node differ by at most one; if at any time they differ by more than one,
rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n
is the number of nodes in the tree prior to the operation.  Insertions and deletions may require tree to be rebalanced by one or more rotations.

**** left left left right rotation on AVL tree ****
*/

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << "  " << flush;
        inorder(p->rchild);
    }
}

int nodeHeight(struct Node *p) {
    int hl,hr;
    hl = p && p->lchild?p->lchild->height:0;
    hr = p && p->rchild?p->rchild->height:0;

    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct Node *p) {
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node * leftLeftRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

struct Node * leftRightRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

struct Node * rightRightRotation(struct Node *p) {
    return NULL;
}

struct Node * rightLeftRotation(struct Node *p) {
    return NULL;
}

struct Node* recursiveInsert(struct Node *p,int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;

    return t;
    }

    if (key < p->data)
        p->lchild = recursiveInsert(p->lchild,key);
    else if (key > p->data)
        p->rchild = recursiveInsert(p->rchild,key);

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 &&  balanceFactor(p->lchild) == 1)
        return leftLeftRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return leftRightRotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return rightRightRotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return rightLeftRotation(p);

    return p;
}

int main() {
    cout << "**** left left left right rotation on AVL tree ****\n";
    struct Node *result;
    root = recursiveInsert(root,52);
    recursiveInsert(root,14);
    recursiveInsert(root,29);
    recursiveInsert(root,66);
    inorder(root);

    return 0;
}
