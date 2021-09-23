/*
AVL tree is a height-balanced binary search tree.  A binary tree is said to be balanced if the difference between the heights of left and right
subtrees of every node is either -1, 0 or 1.  The AVL tree was created in year 1962 by G.M. Adelson-Velsky and E.M. Landis and contains
balance factor information about node.

**** left right right right rotation on AVL tree ****
*/
#include <iostream>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    // helper methods for inserting
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    Node* leftLeftRotation(Node* p);
    Node* rightRightRotation(Node* p);
    Node* leftRightRotation(Node* p);
    Node* rightLeftRotation(Node* p);
    // insert
    Node* recursiveInsert(Node* p, int key);

    // traversal
    void inorder(Node* p);
    void inorder() {
        inorder(root);
    }

    Node* getRoot() {
        return root;
    }
};

int AVL::nodeHeight(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::balanceFactor(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}

Node* AVL::leftLeftRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;

    // update height
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    // update root
    if (root == p) {
        root = pl;
    }

    return pl;
}

Node* AVL::rightRightRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;

    // update height
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    // update root
    if (root == p) {
        root = pr;
    }

    return pr;
}

Node* AVL::leftRightRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    // update height
    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    // update root
    if (p == root) {
        root = plr;
    }
    return plr;
}

Node* AVL::rightLeftRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;

    // update height
    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    // update root
    if (root == p) {
        root = prl;
    }
    return prl;
}

Node* AVL::recursiveInsert(Node *p,int key) {
    Node* t;
    if (p == nullptr) {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        // starting height from 1 onwards instead of 0
        t->height = 1;

        return t;
    }

    if (key < p->data) {
        p->lchild = recursiveInsert(p->lchild,key);
    }
    else if (key > p->data) {
        p->rchild = recursiveInsert(p->rchild,key);
    }

    // update height
    p->height = nodeHeight(p);

    // balance factor and rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return leftLeftRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return leftRightRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return rightRightRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
        return rightLeftRotation(p);
    }

    return p;
}

void AVL::inorder(Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " " << flush;
        inorder(p->rchild);
    }
}

int main() {
    cout << "**** left right right right rotation on AVL tree ****\n";
    // left right rotation
    AVL treeLeftRight;
    treeLeftRight.root = treeLeftRight.recursiveInsert(treeLeftRight.root,52);
    treeLeftRight.root = treeLeftRight.recursiveInsert(treeLeftRight.root,11);
    treeLeftRight.root = treeLeftRight.recursiveInsert(treeLeftRight.root,27);
    treeLeftRight.inorder();

    cout << endl;
    cout << "root data: " << treeLeftRight.root->data << endl;

    // right left rotation
    AVL treeRightLeft;
    treeRightLeft.root = treeRightLeft.recursiveInsert(treeRightLeft.root,23);
    treeRightLeft.root = treeRightLeft.recursiveInsert(treeRightLeft.root,59);
    treeRightLeft.root = treeRightLeft.recursiveInsert(treeRightLeft.root, 34);
    treeRightLeft.inorder();

    cout << endl;
    cout << "root data: " << treeRightLeft.root->data << endl;

    return 0;
}
