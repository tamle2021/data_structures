/*
An AVL Tree is a binary search tree such that for every internal node v of T, the heights of the children of v can differ by at most 1.
The height of an AVL tree T storing n keys is O(log n).

**** deletion from AVL tree with rotation ****
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

    // helper methods for inserting/deleting
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    Node* leftLeftRotation(Node* p);
    Node* rightRightRotation(Node* p);
    Node* leftRightRotation(Node* p);
    Node* rightLeftRotation(Node* p);
    Node* inPre(Node* p);
    Node* inSucc(Node* p);
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

    // delete
    Node* deleteIt(Node* p,int key);
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

Node* AVL::inPre(Node *p) {
    while (p && p->rchild != nullptr) {
        p = p->rchild;
    }

    return p;
}

Node* AVL::inSucc(Node *p) {
    while (p && p->lchild != nullptr) {
        p = p->lchild;
    }

    return p;
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
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return leftRightRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return rightRightRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
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

Node* AVL::deleteIt(Node *p,int key) {
    if (p == nullptr) {
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr) {
        if (p == root) {
            root = nullptr;
        }

        delete p;
        return nullptr;
    }

    if (key < p->data) {
        p->lchild = deleteIt(p->lchild,key);
    }
    else if (key > p->data) {
        p->rchild = deleteIt(p->rchild,key);
    }
   else {
        Node* q;
        if (nodeHeight(p->lchild) > nodeHeight(p->rchild)) {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = deleteIt(p->lchild,q->data);
        }
        else {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = deleteIt(p->rchild,q->data);
        }
    }

    // update height
    p->height = nodeHeight(p);

    // balance factor and rotation
    // L1 rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return leftLeftRotation(p);

    }
    // L-1 rotation
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return leftRightRotation(p);
    }
     // R-1 rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return rightRightRotation(p);
    }
    // R1 rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
        return rightLeftRotation(p);
    }
    // L0 rotation
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0) {
        return leftLeftRotation(p);
    }
    // R0 Rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0) {
        return rightRightRotation(p);
    }

    return p;
}

int main() {
    cout << "**** deletion on AVL tree with rotation ****\n";
    AVL avlTree;
    int A[] = {14,25,33,24,21,20,3};
    for (int i=0; i < sizeof(A) / sizeof(A[0]); i++){
        avlTree.root = avlTree.recursiveInsert(avlTree.root,A[i]);
    }

    avlTree.inorder();
    cout << endl;

    avlTree.deleteIt(avlTree.root,24);
    avlTree.inorder();
    cout << endl;

    return 0;
}
