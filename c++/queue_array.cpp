/*
In computer science, a queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities
at one end of sequence and the removal of entities from other end of sequence.  This queue implementation uses array and follows first in
first out structure.
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

void createQueue(struct Queue *q,int size) {
    // allocate memory
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q,int x) {
    if (q->rear == q->size - 1)
        printf("queue is full");
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear)
        printf("queue is empty\n");
    else {
        q->front++;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Queue q) {
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ",q.Q[i]);

    printf("\n");
}

int main() {
    cout << "**** queue using array ****\n";
    struct Queue q;
    createQueue(&q,7);
    enqueue(&q,5);
    enqueue(&q,15);
    enqueue(&q,33);
    enqueue(&q,25);
    enqueue(&q,111);
    display(q);
    printf("%d ",dequeue(&q));

    return 0;
}
