/*

**** binary tree using queue c++ implementation ****
*/


#include <iostream>
#include<stdio.h>

using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue() {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new Node *[size];
    }

    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() {
        return front == rear;
    }
};

void Queue::enqueue(Node *x) {
    if (rear == size - 1)
        printf("queue full....\n");
    else {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue() {
    Node *x = NULL;
    if (front == rear)
        printf("queue is empty....\n");
    else {
        x = Q[front+1];
        front++;
    }

    return x;
}

class Tree {
    Node *root;
public:
    Tree() {
        root = NULL;
    }

    void createTree();
    void preorder() {
        preorder(root);
    }
    void preorder(Node *p);
    void postorder() {
        postorder(root);
    }
    void postorder(Node *p);

    void inorder() {
        inorder(root);
    }
    void inorder(Node *p);
    void levelorder() {
        levelorder(root);
    }
    void levelorder(Node *p);
    int height() {
        return height(root);
    }
    int height(Node *root);
};

void Tree::createTree() {
    Node *p,*t = NULL;
    int x;
    Queue q(4);
    printf("enter root value: ");
    scanf("%d",&x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()) {
        p = q.dequeue();
        printf("enter left child of %d: ",p->data);
        scanf("%d",&x);

        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("enter right child of %d: ",p->data);
        scanf("%d",&x);

        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(struct Node *p) {
    if (p) {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void Tree::postorder(struct Node *p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Tree::levelorder(struct Node *p) {
    Queue q(100);
    printf("%d ",root->data);
    q.enqueue(root);

    while(!q.isEmpty()) {
        root = q.dequeue();
        if (root->lchild) {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }

        if (root->rchild) {
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int Tree::height(struct Node *root) {
    int x = 0,y = 0;
    if (root == 0)
        return 0;

    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main() {
    cout << "**** binary tree using queue c++ implementation ****\n";
    Tree t;
    t.createTree();

    cout << "preorder: ";
    t.preorder();
    cout << endl;
    cout << "inorder: ";
    t.inorder();
    cout << endl << endl;

    return 0;
}
