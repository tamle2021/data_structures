/*
AVL trees are binary search trees in which the difference between height of  left and right subtree is either -1, 0, or 1.
AVL trees are also called a self-balancing binary search tree. These trees help to maintain the logarithmic search time. It is named after its
 inventors Adelson, Velsky, and Landis.

*** Left left, right right rotation on avl tree ***

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

    // helper methods for insertion
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    Node* leftLeftRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* leftRightRotation(Node* p);
    Node* rightLeftRotation(Node* p);

    // insert
    Node* rInsert(Node* p, int key);

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

Node* AVL::RRRotation(Node *p) {
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
    return nullptr;
}

Node* AVL::rightLeftRotation(Node *p) {
    return nullptr;
}

Node* AVL::rInsert(Node *p,int key) {
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
        p->lchild = rInsert(p->lchild,key);
    }
    else if (key > p->data) {
        p->rchild = rInsert(p->rchild,key);
    }

    // update height
    p->height = nodeHeight(p);

    // balance factor and rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return leftLeftRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return leftRightRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
        return rightLeftRotation(p);
    }

    return p;
}

void AVL::inorder(Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << "  " << flush;
        inorder(p->rchild);
    }
}


int main() {
    cout << "**** left left right right rotation on AVL tree ****\n";
    // left left rotation
    AVL leftLeftTree;
    leftLeftTree.root = leftLeftTree.rInsert(leftLeftTree.root,34);
    leftLeftTree.root = leftLeftTree.rInsert(leftLeftTree.root,22);
    leftLeftTree.root = leftLeftTree.rInsert(leftLeftTree.root,13);

    leftLeftTree.inorder();
    cout << endl;

    // right right rotation
    AVL rightRightTree;
    rightRightTree.root = rightRightTree.rInsert(rightRightTree.root,14);
    rightRightTree.root = rightRightTree.rInsert(rightRightTree.root,27);
    rightRightTree.root = rightRightTree.rInsert(rightRightTree.root,39);

    rightRightTree.inorder();
    cout << endl;

    return 0;
}
