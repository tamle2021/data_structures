/*




**** stack using array ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *stk,int size1) {
    stk->top = -1;
    stk->size = size1;
    stk->S = (int *)malloc(stk->size * sizeof(int));
}

void displayIt(struct Stack stk) {
    int i;

    for (i = stk.top; i >= 0; i--)
        printf("%d ",stk.S[i]);
    printf("\n");
}

void pushIt(struct Stack *st,int x) {
    if (st->top == st->size - 1)
        printf("stack overflow....");
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

int popIt(struct Stack *st) {
    int x = -1;

    if (st->top == -1)
        printf("stack underflow....");
    else {
        x = st->S[st->top--];
    }

    return x;
}

int peek(struct Stack st,int index) {
    int x = -1;

    if (st.top - index + 1 < 0)
        printf("invalid index....");

    x = st.S[st.top - index + 1];
    return x;
}

int isEmpty(struct Stack st) {
    if (st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st) {
    return st.top == st.size - 1;
}

int topStack(struct Stack stk) {
    if (!isEmpty(stk))
        return stk.S[stk.top];

    return -1;
}

int main() {
    cout << "**** stack using array ****\n";
    struct Stack stk;
    int size1 = 6;
    int peek1 = 3;
    int poppedElem = 0;

    create(&stk,size1);
    pushIt(&stk,14);
    pushIt(&stk,29);
    pushIt(&stk,34);
    pushIt(&stk,49);
    pushIt(&stk,91);

    cout << "before pop: ";
    displayIt(stk);

    cout << "after pop: ";
    poppedElem = popIt(&stk);
    displayIt(stk);
    cout << "popped element: " << poppedElem << "\n";

    // peek not working after pop
    // cout << "peek at element " << peek1 << ": ";
    // printf("%d \n",peek(stk,peek1));

    return 0;
}
