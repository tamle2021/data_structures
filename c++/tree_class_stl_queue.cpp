/*

**** tree class using STL queue c++ implementation ****
*/
#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Tree {
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void createTree();
    void preorder(Node* p);
    // passing private parameter in constructor
    void preorder() {
        preorder(root);
    }
    void inorder(Node* p);
    void inorder() {
        inorder(root);
    }

    void postorder(Node* p);
    void postorder() {
        postorder(root);
    }
    void levelorder(Node* p);
    void levelorder() {
        levelorder(root);
    }
    int height(Node* p);
    int height() {
        return height(root);
    }
};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    // TODO
}

void Tree::createTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "enter root: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "enter left child of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "enter right child of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::preorder(Node *p) {
    if (p) {
        cout << p->data << ", " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}

void Tree::postorder(Node *p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " " << flush;
    }
}

void Tree::levelorder(Node *p) {
    queue < Node* > q;
    cout << root->data << " " << flush;
    q.emplace(root);

    while (! q.empty()) {
        p = q.front();
        q.pop();

        if (p->lchild) {
            cout << p->lchild->data << " " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild) {
            cout << p->rchild->data << " " << flush;
            q.emplace(p->rchild);
        }
    }
}

int Tree::height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr) {
        return 0;
    }

    l = height(p->lchild);
    r = height(p->rchild);

    if (l > r) {
        return l + 1;
    }
    else {
        return r + 1;
    }
}


int main() {
    cout << "**** tree class using STL queue c++ implementation ****\n";
    Tree bt;
    bt.createTree();
    cout << endl;

    cout << "preorder: " << flush;
    bt.preorder();
    cout << endl;

    cout << "inorder: " << flush;
    bt.inorder();
    cout << endl;

    cout << "postorder: " << flush;
    bt.postorder();
    cout << endl;

    cout << "levelorder: " << flush;
    bt.levelorder();
    cout << endl;
    cout << "height: " << bt.height() << endl;

    return 0;
}
