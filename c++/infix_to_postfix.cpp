/*




**** infix to postfix conversion ****

*/
#include <stdio.h>
#include <stdlib.h>
// #include <strings.h>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    char data;
    struct Node *next;
}*top=NULL;

void pushIt(char x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full....");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char popIt() {
    struct Node *t;
    char x = -1;

    if (top == NULL)
        printf("stack is empty....");
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

int isBalanced(char *exp) {
    int i;

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            pushIt(exp[i]);
        else if (exp[i] == ')') {
            if (top == NULL)
                return 0;
            popIt();
        }
    }

    if (top == NULL)
        return 1;
    else
        return 0;
}

int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;

    return 0;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char * inToPost(char *infix) {
    int i = 0,j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (pre(infix[i]) > pre(top->data))
                pushIt(infix[i++]);
            else {
                postfix[j++] = popIt();
            }
        }
    }

    while (top != NULL)
        postfix[j++] = popIt();

    postfix[j] = '\0';
    return postfix;
}

int main() {
    cout << "**** infix to postfix conversion ****\n";
    char *infix = "e-f*g+h/i";
    pushIt('#');
    char *postfix = inToPost(infix);

    cout << "infix: ";
    for (int i = 0; i <= sizeof(infix) / sizeof(infix[0]); i++)
        cout << infix[i];
    cout << endl;

    cout << "postfix: ";
    printf("%s ",postfix);
    return 0;
}
