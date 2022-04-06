/*


**** double-ended queue using array c++ implementation ****

*/
#include <iostream>

using namespace std;

class Dequeue {
private:
    int front;
    int rear;
    int size;
    int* Q;

public:
    Dequeue(int size);
    ~Dequeue();
    void displayIt();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};

Dequeue::Dequeue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}

Dequeue::~Dequeue() {
    delete [] Q;
}

bool Dequeue::isEmpty() {
    if (front == rear) {
        return true;
    }

    return false;
}

bool Dequeue::isFull() {
    if (rear == size - 1) {
        return true;
    }

    return false;
}

void Dequeue::enqueueFront(int x) {
    if (front == -1) {
        cout << "double-ended queue overflow...." << endl;
    }
    else {
        Q[front] = x;
        front--;
        cout << "enqueue front...." << endl;
    }
}

void Dequeue::enqueueRear(int x) {
    if (isFull()) {
        cout << "double-ended queue overflow...." << endl;
    }
    else {
        rear++;
        Q[rear] = x;
        cout << "enqueue rear....\n";
    }
}

int Dequeue::dequeueFront() {
    int x = -1;

    if (isEmpty()) {
        cout << "double-ended queue underflow...." << endl;
    }
    else {
        x = Q[front];
        front++;
        cout << "dequeue front....\n";
    }

    return x;
}

int Dequeue::dequeueRear() {
    int x = -1;

    if (rear == -1) {
        cout << "double-ended queue underflow...." << endl;
    }
    else {
        x = Q[rear];
        rear--;
        cout << "dequeue rear...." << endl;
    }

    return x;
}

void Dequeue::displayIt() {
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " => " << flush;
        }
    }

    cout << endl;
}

int main() {
    cout << "**** double-ended queue using array c++ implementation ****\n";
    int x = 0;
    int A[] = {14,30,0,4,2};
    int B[] = {3,41,64,11,7};

    Dequeue deq(sizeof(A) / sizeof(A[0]));
    // Dequeue deqB(sizeof(B) / sizeof(B[0]));

    for (long long unsigned int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        deq.enqueueRear(A[i]);
    }
    deq.displayIt();

    cout << "enqueue rear => ";
    deq.enqueueRear(11);
    cout << "display: ";
    deq.displayIt();

    for (long long unsigned int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        x = deq.dequeueFront();
        cout << "dequeue front ---- " << x << endl;
    }

    cout << "dequeue front again => ";
    deq.dequeueFront();
    cout << endl;

    cout << "enqueue front b array: " << endl;
    for (long long unsigned int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        deq.enqueueFront(B[i]);
    }
    cout << "display b array: \n";
    deq.displayIt();
    cout << "enqueue front: \n";
    deq.enqueueFront(19);
    cout << "display b array: \n";
    deq.displayIt();
    cout << "enqueue front: \n";
    deq.enqueueFront(111);

    for (long long unsigned int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        x = deq.dequeueRear();
        cout << "dequeue rear --- " << x << endl;
    }
    cout << "display b array: \n";
    deq.displayIt();
    cout << "dequeue rear: \n";
    deq.dequeueRear();
    deq.dequeueRear();

    return 0;
}
