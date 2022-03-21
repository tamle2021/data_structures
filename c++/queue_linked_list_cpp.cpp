/*


**** queue using linked list c++ implementation ****

*/
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void displayIt();
};

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "queue overflow...." << endl;
    }
    else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr){
            front = t;
            rear = t;
        }
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue() {
    int x = -1;
    Node* p;

    if (isEmpty()) {
        cout << "queue underflow...." << endl;
    }
    else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }

    return x;
}

bool Queue::isEmpty() {
    if (front == nullptr) {
        return true;
    }

    return false;
}

Queue::~Queue() {
    Node* p = front;

    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::displayIt() {
    Node* p = front;

    if (!p)
        cout << "empty....";
    else  {
        while (p) {
            cout << p->data << flush;
            p = p->next;
            if (p != nullptr) {
                cout << " --> " << flush;
            }
        }
    }

    cout << endl;
}

int main() {
    cout << "**** queue using linked list c++ implementation ****\n";
    int A[] = {11,34,54,71,90,0,-22};
    int x = 0;

    Queue q;
    for (long long unsigned i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.enqueue(A[i]);
    }

    q.displayIt();

    for (long long unsigned i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        x = q.dequeue();
        cout << "dequeue - " << x << endl;
    }

    cout << "display after dequeue: \n";
    q.displayIt();

    cout << "dequeue again....\n";
    q.dequeue();

    return 0;
}
