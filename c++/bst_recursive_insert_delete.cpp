/*
Binary search tree with insert and delete

*/

#include <iostream>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iterativeInsert(int key);
    void inorder(Node* p);
    Node* iterativeSearch(int key);
    Node* recursiveInsert(Node* p, int key);
    Node* recursiveSearch(Node* p, int key);
    Node* deleteIt(Node* p, int key);
    int height(Node* p);
    Node* inorderPredecessor(Node* p);
    Node* inorderSuccessor(Node* p);
};

void BST::iterativeInsert(int key) {
    Node* t = root;
    Node* p;
    Node* r;

    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while(t != nullptr) {
        r = t;
        if (key < t->data) {
            t = t->lchild;
        }
        else if (key > t->data) {
            t = t->rchild;
        }
        else {
            return;
        }
    }

    // t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }

}

void BST::inorder(Node* p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " " << flush;
        inorder(p->rchild);
    }
}

Node* BST::iterativeSearch(int key) {
    Node* t = root;
    while (t != nullptr) {
        if (key == t->data) {
            return t;
        }
        else if (key < t->data) {
            t = t->lchild;
        }
        else {
            t = t->rchild;
        }
    }
    return nullptr;
}

Node* BST::recursiveInsert(Node *p,int key) {
    Node* t;
    if (p == nullptr) {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    if (key < p->data) {
        p->lchild = recursiveInsert(p->lchild,key);
    }
    else if (key > p->data) {
        p->rchild = recursiveInsert(p->rchild,key);
    }
    // key == p->data
    return p;
}

Node* BST::recursiveSearch(Node *p,int key) {
    if (p == nullptr) {
        return nullptr;
    }

    if (key == p->data) {
        return p;
    }
    else if (key < p->data) {
        return recursiveSearch(p->lchild, key);
    }
    else {
        return recursiveSearch(p->rchild, key);
    }
}

Node* BST::deleteIt(Node *p,int key) {
    Node* q;
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
        p->lchild = deleteIt(p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = deleteIt(p->rchild, key);
    }
    else {
        if (height(p->lchild) > height(p->rchild)) {
            q = inorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = deleteIt(p->lchild,q->data);
        }
        else {
            q = inorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = deleteIt(p->rchild,q->data);
        }
    }
    return p;
}

int BST::height(Node *p) {
    int x;
    int y;
    if (p == nullptr) {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node* BST::inorderPredecessor(Node *p) {
    while (p && p->rchild != nullptr) {
        p = p->rchild;
    }
    return p;
}

Node* BST::inorderSuccessor(Node *p) {
    while (p && p->lchild != nullptr) {
        p = p->lchild;
    }
    return p;
}

int main() {
    BST bst;
    cout << "**** binary search tree with recursive insert & delete ****\n";
    // iterative insert
    bst.iterativeInsert(4);
    bst.iterativeInsert(22);
    bst.iterativeInsert(0);
    bst.iterativeInsert(-27);
    bst.iterativeInsert(89);
    bst.iterativeInsert(134);
    bst.iterativeInsert(111);

    // inorder traversal
    bst.inorder(bst.getRoot());
    cout << endl;

    // iterative search
    Node* temp = bst.iterativeSearch(2);
    if (temp != nullptr) {
        cout << "element found: " << temp->data << endl;
    } else {
        cout << "element not found: 2" << endl;
    }

    // recursive search
    temp = bst.recursiveSearch(bst.getRoot(),0);
    if (temp != nullptr) {
        cout << "element found: " << temp->data << endl;
    } else {
        cout << "element not found: 0" << endl;
    }

    // recursive insert
    bst.recursiveInsert(bst.getRoot(),88);
    bst.recursiveInsert(bst.getRoot(),74);
    bst.recursiveInsert(bst.getRoot(),25);
    bst.inorder(bst.getRoot());
    cout << "\n" << endl;

    // inorder predecessor and inorder successor
    BST bs;
    bs.iterativeInsert(21);
    bs.iterativeInsert(-5);
    bs.iterativeInsert(13);
    bs.iterativeInsert(17);
    bs.iterativeInsert(44);
    bs.iterativeInsert(91);

    temp = bs.inorderPredecessor(bs.getRoot());
    cout << "inorder predecessor: " << temp->data << endl;

    temp = bs.inorderSuccessor(bs.getRoot());
    cout << "inorder successor: " << temp->data << endl;

    bs.inorder(bs.getRoot());
    cout << endl;
    // delete
    bs.deleteIt(bs.getRoot(),7);
    bs.inorder(bs.getRoot());

    return 0;
}
