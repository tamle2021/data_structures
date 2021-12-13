/*
example => enter number of terms: 2
           enter each term with coeff and exponent: 6 1
                                                    4 0

**** polynomial linked list ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

struct Node {
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create() {
    struct Node *t,*last=NULL;
    int num,i;

    printf("enter number of terms: ");
    scanf("%d",&num);
    printf("enter each term with coeff and exponent: \n");
    for(i = 0; i < num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d %d",&t->coeff,&t->exp);
        t->next = NULL;

        if (poly == NULL) {
            poly = last = t;
        }
        else {
            last->next = t;
            last = t;
        }
    }
}

void displayIt(struct Node *p) {
    while(p) {
        printf("%dx%d + ",p->coeff,p->exp);
        p = p->next;
    }

    printf("\n");
}

long evaluation(struct Node *p,int x) {
    long val = 0;
    while(p) {
        val += p->coeff * pow(x,p->exp);
        p = p->next;
    }

    return val;
}

int main() {
    cout << "**** polynomial linked list ****\n";
    create();
    displayIt(poly);

    cout << "evaluation: " << endl;
    printf("%ld\n",evaluation(poly,1));

    return 0;
}
