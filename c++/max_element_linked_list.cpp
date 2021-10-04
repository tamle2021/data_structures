/*

**** max element from linked list ****
*/
#define __STDC_LIMIT_MACROS
#include <stdint.h>
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

int maxIt(struct Node *p) {
    int max = INT32_MIN;
    while (p) {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

int recursiveMax(struct Node *p) {
    int x = 0;
    if (p == 0)
        return INT32_MIN;

    x = recursiveMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

int main() {
    cout << "**** max element from linked list ****\n";
    int A[] = {33,4,11,13,99,-4,0,22,55,41,17};
    int B[] = {3,44,9,11,-5,3,2,77,84,-13,2,154};

    create(A,11);
    printf("maximum: %d\n",maxIt(first));
    create(B,12);
    cout << "recursive max: " << recursiveMax(first) << "\n";

    return 0;
}
