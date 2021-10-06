/*

**** stack using linked list ****
*/

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "stack overflow...." << endl;
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == nullptr) {
        cout << "stack underflow: \nreturn element => ";
    }
    else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }

    return x;
}

int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;

    return r;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}

int Stack::stackTop() {
    if (top) {
        return top->data;
    }
    return -1;
}

int Stack::peek(int index) {
    if (isEmpty()) {
        return -1;
    }
    else {
        Node* p = top;
        for (int i = 0; p != nullptr && i < index - 1; i++) {
            p = p->next;
        }

        if (p != nullptr) {
            return p->data;
        }
        else {
            return -1;
        }
    }
}

int main() {
    cout << "**** stack using linked list ****\n";
    int A[] = {11,34,15,3,0,9,44};
    Stack stk;

    // populate stack
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        stk.push(A[i]);
    }

    cout << "stack peek at 4: " << stk.peek(4) << endl;
    cout << "stack peek at 9: " << stk.peek(9) << endl;
    cout << "stack top: " << stk.stackTop() << endl;
    cout << "is stack full? " << stk.isFull() << endl;
    cout << "is stack empty? " << stk.isEmpty() << endl;

    // pop out elements from stack
    cout << "popped: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++){
        cout << stk.pop() << " " << flush;
    }

    cout << endl;
    // underflow
    cout << stk.pop() << endl;

    return 0;
}
