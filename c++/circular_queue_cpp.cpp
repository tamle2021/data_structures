/*
1) In case of circular queue, head pointer will point to front of queue and tail pointer will point to end of queue.
2) Initially, the head and tail pointers will point to the same location and this would mean that queue is empty.
3) New data is always added to location pointed by the tail pointer and once data is added, tail pointer is incremented to point to
next available location.
4) In a circular queue, data is not actually removed from the queue. Only the head pointer is incremented by one position when
dequeue is executed.  As queue data is only data between the head and tail, hence data left outside is not a part of the queue anymore
and removed.
5) Head and tail pointers will get re-initialized to 0 every time they reach end of the queue.
6) Also, head and tail pointers can cross each other.  In other words, head pointer can be greater than tail.  This will happen
when queue gets dequeued a couple of times and tail pointer gets re-initialized upon reaching end of the queue.

**** circular queue c++ implementation ****

*/
#include <iostream>

using namespace std;

class CircularQueue {
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size];
}

CircularQueue::~CircularQueue() {
    delete [] Q;
}

bool CircularQueue::isEmpty() {
    if (front == rear) {
        cout << "front - " << front << "   rear - " << rear << endl;
        return true;
    }

    return false;
}

bool CircularQueue::isFull() {
    if ((rear + 1) % size == front) {
        return true;
    }

    return false;
}

void CircularQueue::enqueue(int x) {
    if (isFull()) {
        cout << "queue overflow...." << endl;
    }
    else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue() {
    int x = -1;

    if (isEmpty()) {
        cout << "queue underflow...." << endl;
    }
    else {
        front = (front + 1) % size;
        x = Q[front];
    }

    return x;
}

void CircularQueue::display() {
    int i = front + 1;

    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " --> " << flush;
        }

        i = (i + 1) % size;

    } while (i != (rear + 1) % size);
}

int main() {
    cout << "**** circular queue c++ implementation ****\n";
    int A[] = {4,11,19,57,81,167,0};
    int b = 0;
    CircularQueue cq(sizeof(A) / sizeof(A[0]) + 1);

    // enqueue
    for (long long unsigned i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cq.enqueue(A[i]);
    }

    // display
    cq.display();
    cout << endl;
    // overflow
    cout << "try to enqueue another one --- ";
    cq.enqueue(10);

    // dequeue
    for (long long unsigned i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        b = cq.dequeue();
        cout << "dequeue --- " << b << endl;
    }

    cout << "call display after dequeue =>";
    cq.display();

    // underflow
    cout << "\ndequeue again....\n";
    cq.dequeue();

    return 0;
}
