/*

**** count and sum of linked list ****
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

    for(i = 1; i < n; i++) {
         // memory allocation
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p) {
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }

    return l;
}

int recursiveCount(struct Node *p) {
    if (p != NULL)
        return recursiveCount(p->next) + 1;
    else
        return 0;
}

int sum(struct Node *p) {
    int s = 0;
    while (p != NULL) {
        s += p->data;
        p = p->next;
    }

    return s;
}

int recursiveSum(struct Node *p) {
    if (p == NULL)
        return 0;
    else
        return recursiveSum(p->next) + p->data;
}

int main() {
    cout << "**** count and sum of linked list ****\n";
    int A[] = {25,4,9,12,24,0,1,29,-9,128};
    create(A,10);
    printf("count: %d\n",count(first));
    printf("sum: %d\n",sum(first));
    cout << "recursive count: " << recursiveCount(first) << endl;
    cout << "recursive sum: " << recursiveSum(first) << "\n";

    return 0;
}
