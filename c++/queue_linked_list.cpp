/*


**** queue using linked list ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("queue full....\n");
    else {
        t->data = x;
        t->next = NULL;

        if (front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue() {
    int x = -1;
    struct Node* t;

    if (front == NULL)
        printf("queue empty....\n");
    else {
        x = front->data;
        t = front;
        front = front->next;

        free(t);
    }

    return x;
}

void displayIt() {
    struct Node *p = front;

    while(p) {
        printf("%d ",p->data);
        p = p->next;
    }

    printf("\n");
}

int main() {
    cout << "**** queue using linked list ****\n";

    enqueue(7);
    enqueue(14);
    enqueue(92);
    enqueue(0);
    enqueue(-5);
    enqueue(11);

    cout << "display queue: " << endl;
    displayIt();
    cout << "dequeue operation: ";
    printf("%d ",dequeue());

    cout << "\ndisplay queue: " << endl;
    displayIt();

    return 0;
}
