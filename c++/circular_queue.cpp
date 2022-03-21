/*


**** circular queue ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q,int x) {
    if ((q->rear + 1) % q->size == q->front)
        printf("queue full....");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;

    if (q->front == q->rear)
        printf("queue empty....\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

void displayIt(struct Queue q) {
    int i = q.front + 1;

    do {
        printf("%d ",q.Q[i]);
        i = (i + 1) % q.size;

    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}

int main() {
    cout << "**** circular queue ****\n";
    struct Queue q;

    create(&q,8);
    enqueue(&q,7);
    enqueue(&q,14);
    enqueue(&q,33);
    enqueue(&q,25);
    enqueue(&q,4);
    enqueue(&q,92);
    enqueue(&q,-5);

    displayIt(q);
    cout << "dequeue operation: ";
    printf("%d \n",dequeue(&q));

    cout << "display queue: ";
    displayIt(q);

    return 0;
}
