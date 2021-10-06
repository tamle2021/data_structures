/*

**** tree class using array queue ****
*/
#include <iostream>

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue{
private:
    int size;
    int front;
    int rear;
    // [Node*]*: pointer to [pointer to Node]
    Node** Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};

Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}

// destructor
Queue::~Queue() {
    delete [] Q;
}

bool Queue::isEmpty() {
    if (front == rear) {
        return true;
    }

    return false;
}

bool Queue::isFull() {
    if (rear == size - 1) {
        return true;
    }

    return false;
}

void Queue::enqueue(Node* x) {
    if (isFull()) {
        cout << "queue overflow...." << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()) {
        cout << "queue underflow...." << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}


class Tree{
private:
    Node* root;
public:
    Tree() {
        root = nullptr;
    }
    ~Tree();
    void createTree();
    void preorder() {
        preorder(root);
    }
    void preorder(Node* p);
    void postorder(){
        postorder(root);
    }
    void postorder(Node* p);
    void inorder() {
        inorder(root);
    }
    void inorder(Node* p);
    // passing private parameter in constructor
    void levelorder() {
        levelorder(root);
    }
    void levelorder(Node* p);
    int height() {
        return height(root);
    }
    int height(Node* p);
    Node* getRoot() {
        return root;
    }
};

void Tree::createTree() {
    Node* p;
    Node* t;
    int x;

    Queue q(3);
    root = new Node;
    cout << "enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty()) {
        p = q.dequeue();

        cout << "enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "enter right child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p) {
    if (p) {
        cout << p->data << " " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " " << flush;
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
    Queue q(100);
    cout << root->data << " " << flush;
    q.enqueue(root);

    while (!q.isEmpty()) {
        p = q.dequeue();
        if (p->lchild) {
            cout << p->lchild->data << " " << flush;
            q.enqueue(p->lchild);
        }
        if (p->rchild) {
            cout << p->rchild->data << " " << flush;
            q.enqueue(p->rchild);
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

Tree::~Tree() {
    // TODO
}


int main(){
    cout << "**** tree class using array queue ****\n";
    Tree t;
    t.createTree();

    cout << "pre-order: " << flush;
    t.preorder(t.getRoot());
    cout << endl;
    cout << "in-order: " << flush;
    t.inorder(t.getRoot());
    cout << endl;

    cout << "post-order: " << flush;
    t.postorder(t.getRoot());
    cout << endl;
    cout << "level-order: " << flush;
    t.levelorder(t.getRoot());
    cout << endl;
    cout << "height: " << t.height(t.getRoot()) << endl;

    // *************************************************************************
    cout << "recursive passing private parameter in constructor" << endl;
    cout << "pre-order: " << flush;
    t.preorder();
    cout << endl;
    cout << "in-order: " << flush;
    t.inorder();
    cout << endl;
    cout << "post-order: " << flush;
    t.postorder();
    cout << endl;

    cout << "level-order: " << flush;
    t.levelorder();
    cout << endl;
    cout << "height: " << t.height() << endl;

    return 0;
}
