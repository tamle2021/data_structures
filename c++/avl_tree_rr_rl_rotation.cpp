/*
AVL tree is conceptualized by GM Adelson, Velsky, and EM Landis in 1962.  AVL tree can be defined as height balanced binary search tree in which
each node is associated with a balance factor calculated by subtracting the height of its right sub-tree from that of left sub-tree.
Tree is said to be balanced if balance factor of each node is between -1 to 1, otherwise, the tree will need to be balanced.
balanceFactor(k) = height(left(k)) - height(right(k))

If balance factor of any node is 0, it means that left sub-tree and right sub-tree have equal height.
**** right right right left rotation on AVL tree ****
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    int bf;
    struct Node *rchild;
}*root = NULL;

int height(struct Node *p) {
    int x = 0,y = 0;
    if (!p)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);

    return x > y ? x+1 : y+1;
}

void insertIt(int key) {
    struct Node *t = root;
    struct Node *r = NULL,*p;

    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->bf = 0;
        p->lchild = p->rchild = NULL;
        root = p;

       return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key>t->data)
            t = t->rchild;
        else

        return;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

struct Node * leftLeftRotation(struct Node *p) {
    int lbf,rbf;
    struct Node *pl = p->lchild;
    pl->bf = 0;
    p->lchild = pl->rchild;
    pl->rchild = p;
    lbf = height(p->lchild) + 1;
    rbf = height(p->rchild) + 1;
    p->bf = lbf - rbf;

    if (p == root)
        root=pl;

    return pl;
}

struct Node* leftRightRotation(struct Node *p) {
    int lbf,rbf;
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    plr->bf = 0;
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;
    lbf = height(p->lchild) + 1;
    rbf = height(p->rchild) + 1;
    p->bf = lbf - rbf;
    lbf = height(pl->lchild) + 1;
    rbf = height(pl->rchild) + 1;
    pl->bf = lbf-rbf;

    if (p == root)
        root = plr;

    return plr;
}

struct Node *rightRightRotation(struct Node *p) {
    int lbf,rbf;
    struct Node *pr = p->rchild;
    pr->bf = 0;
    p->rchild = pr->lchild;
    pr->lchild = p;
    lbf = height(p->lchild) + 1;
    rbf = height(p->rchild) + 1;
    p->bf = lbf - rbf;

    if (p == root)
        root = pr;

    return pr;
}

struct Node *rightLeftRotation(struct Node *p) {
    int lbf,rbf;
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;
    prl->bf = 0;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;
    lbf = height(p->lchild) + 1;
    rbf = height(p->rchild) + 1;
    p->bf = lbf-rbf;
    lbf = height(pr->lchild) + 1;
    rbf = height(pr->rchild) + 1;
    pr->bf = lbf - rbf;

    if (p == root)
        root = prl;

    return prl;
}

struct Node* recursiveInsert(struct Node *p,int key) {
    struct Node *t;
    int lbf,rbf;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->bf = 0;
        t->lchild = t->rchild = NULL;

     return t;
    }

    if (key < p->data)
        p->lchild = recursiveInsert(p->lchild,key);
    else if (key > p->data)
        p->rchild = recursiveInsert(p->rchild,key);

    lbf = height(p->lchild) + 1;
    rbf = height(p->rchild) + 1;
    p->bf = lbf - rbf;

    if (p->bf == 2 && p->lchild->bf == 1)
        return leftLeftRotation(p);
    if (p->bf == 2 && p->lchild->bf == -1)
        return leftRightRotation(p);
    if (p->bf ==  -2 && p->rchild->bf == -1)
        return rightRightRotation(p);
    if (p->bf == -2 && p->rchild->bf == 1)
        return rightLeftRotation(p);

    return p;
}
void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

struct Node* searchIt(int key) {
    struct Node *t = root;
    while (t != NULL) {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }

    return NULL;
}

int main() {
    cout << "**** right right right left rotation on AVL tree ****\n";
    struct Node *temp1,*temp2;
    insertIt(34);
    recursiveInsert(root,51);
    recursiveInsert(root,44);
    recursiveInsert(root,27);
    recursiveInsert(root,12);
    recursiveInsert(root,49);
    recursiveInsert(root,41);
    inorder(root);

    printf("\n");
    temp1 = searchIt(49);
    if (temp1 != NULL)
        printf("element %d found\n",temp1->data);
    else
        printf("element not found\n");

    temp2 = searchIt(0);
    if (temp2 != NULL)
        printf("element %d found\n",temp2->data);
    else
        printf("element 0 not found\n");

    return 0;
}
