/*
A queue is a type of data structure where items or tasks sit in a predetermined order to optimize processing of items.


**** queue using array c++ implementation ****
*/
#include <iostream>

using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}

Queue::~Queue() {
    delete [] Q;
}

bool Queue::isEmpty() {
    if (front == rear){
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

void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "queue overflow...." << endl;
    }
    else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (isEmpty()) {
        cout << "queue underflow...." << endl;
    }
    else {
        front++;
        x = Q[front];
    }

    return x;
}

void Queue::display() {
    for (int i = front+1; i <= rear; i++) {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " " << flush;
        }
    }
    cout << endl;
}

int main() {
    cout << "**** queue using array c++ implementation ****\n";
    int A[] = {10,0,4,9,17,24,-4};

    Queue q(sizeof(A) / sizeof(A[0]));

    // enqueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.enqueue(A[i]);
    }

    // display
    q.display();
    // overflow
    q.enqueue(10);

    // dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.dequeue();
    }

    // underflow
    q.dequeue();

    return 0;
}
