
/*
Binary search tree to include insert inorder & search
*/
#include <iostream>

using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST{
private:
    Node* root;
public:
    BST() {
        root = nullptr;
    }
    Node* getRoot() {
        return root;
    }
    void insertIt(int key);
    void inorder(Node* p);
    Node* searchIt(int key);
};

void BST::insertIt(int key) {
    Node* t = root;
    Node* p;
    Node* r;

    // root is empty
    if (root == nullptr) {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr) {
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
        cout << p->data << "  " << flush;
        inorder(p->rchild);
    }
}

Node* BST::searchIt(int key) {
    Node* t = root;
    while (t != nullptr) {
        if (key == t->data) {
            return t;
        }
        else if (key < t->data) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;
}


int main() {
    BST bst;

    cout << "**** binary search tree to include inorder and search ****\n";
    // insert
    bst.insertIt(10);
    bst.insertIt(5);
    bst.insertIt(20);
    bst.insertIt(8);
    bst.insertIt(30);
    bst.insertIt(98);
    bst.insertIt(211);

    // inorder traversal
    bst.inorder(bst.getRoot());
    cout << endl;

    // search
    Node *temp = bst.searchIt(2);
    if (temp != nullptr) {
        cout << "found element: " << temp->data << endl;
    } else {
        cout << "element not found: 2" << endl;
    }

    Node *temp1 = bst.searchIt(211);
    if (temp1 != nullptr) {
        cout << "found element: " << temp1->data << endl;
    } else {
        cout << "element not found: 211"  << endl;
    }

    return 0;
}
