/*
Linked list can be defined as collection of objects called nodes that are randomly stored in memory.  A node contains two fields
which are data stored at that particular address and the pointer which contains address of next node in memory.  The last node of the list contains
a pointer to null.

Display elements of linked list in order and reverse.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[],int n) {
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }

    cout << "\n";
}

void reverseDisplay(struct Node *p) {
    if (p != NULL) {
        reverseDisplay(p->next);
        printf("%d ",p->data);
    }
}

int main() {
    // struct Node *temp;
    int A[] = {3,5,7,10,25,8,32,2};
    cout << "**** linked list ****" << endl;
    cout << "in order: \n";
    create(A,8);
    display(first);
    cout << "reverse order: \n";
    reverseDisplay(first);

    return 0;
}
