/*


**** stack using linked list ****
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

void push(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full....\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("stack is empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }

    return x;
}

void displayIt() {
    struct Node *p;
    p = top;

    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }

    printf("\n");
}

int main() {
    cout << "**** stack using linked list ****\n";
    // pushing values on top of stack
    push(12);
    push(29);
    push(-5);
    push(34);
    push(101);

    displayIt();
    cout << "popping value off stack => " << pop();
    //printf("%d ", pop());

    return 0;
}
