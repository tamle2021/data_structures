/*




**** stack using array c++ implementation ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Stack {
private:
    int size;
    int top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    void pushIt(int x);
    int popIt();
    int peek(int index);
    int isFull();
    int isEmpty();
    void displayIt();
    int topStack();
};

Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new int[size];
}

Stack::~Stack() {
    delete[] S;
}

void Stack::pushIt(int x) {
    if (isFull()) {
        cout << "stack overflow...." << endl;
    }
    else {
        top++;
        S[top] = x;
    }
}

int Stack::popIt() {
    int x = 1;

    if (isEmpty()) {
        cout << "stack underflow...." << endl;
    }
    else {
        x = S[top];
        top--;
    }

    return x;
}

int Stack::peek(int index) {
    int x = -1;

    if (top - index + 1 < 0 || top - index + 1 == size) {
        cout << "invalid position return value => ";
    }
    else {
        x = S[top - index + 1];
    }

    return x;
}

int Stack::isFull() {
    if (top == size - 1) {
        return 1;
    }

    return 0;
}

int Stack::isEmpty() {
    if (top == -1) {
        return 1;
    }

    return 0;
}

void Stack::displayIt() {
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " " << flush;
    }

    cout << endl;
}

int Stack::topStack() {
    if (isEmpty()) {
        return -1;
    }

    return S[top];
}

int main() {
    cout << "**** stack using array c++ implementation ****\n";
    int arr[] = {4,22,0,45,-8,75};
    Stack stk(sizeof(arr) / sizeof(arr[0]));

    // fill the stack
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        stk.pushIt(arr[i]);
    }

    cout << "is stack full? " << stk.isFull() << endl;
    cout << "pushing....\n";
    stk.pushIt(101);
    cout << "is stack full? " << stk.isFull() << endl;

    cout << "stack: " << flush;
    stk.displayIt();

    // peek
    cout << "peek at 0th: " << stk.peek(0) << endl;
    cout << "peek at 1th: " << stk.peek(1) << endl;
    cout << "peek at 4rd: " << stk.peek(4) << endl;
    cout << "peek at 5th: " << stk.peek(5) << endl;

    cout << "top of stack: " << stk.topStack() << endl;

    cout << "popped elements: " << flush;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << stk.popIt() << " " << flush;
    }
    cout << endl;

    cout << "popping....\n";
    stk.popIt();
    cout << "is stack empty? " << stk.isEmpty() << endl;

    return 0;
}
