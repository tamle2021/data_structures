/*
Min heap is a complete binary tree in which value in each internal node is smaller than or equal to the values in the children of that
node.  If a node is stored at index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2.

**** heap sort ****
*/
#include <stdio.h>
#include <iostream>

using namespace std;

void insertIt(int A[],int n) {
    int i = n,temp;
    temp = A[i];

    while(i > 1 && temp > A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }

    A[i] = temp;
}

int deleteIt(int A[],int n) {
    int i,j,x,temp,val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;

    while(j <= n - 1) {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;

        if (A[i] < A[j]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    return val;
}

int main() {
    cout << "**** heap sort ****\n";
    int H[] = {0,13,14,4,27,32,9,55};
    int i;

    cout << "before heap: " << endl;
    for (i = 1; i <= 7; i++)
        printf("%d ",H[i]);
    cout << "\n";

    for (i = 2; i <= 7; i++)
        insertIt(H,i);

    for (i = 7; i > 1; i--) {
        deleteIt(H,i);
    }

    cout << "after heap: " << endl;
    for (i = 1; i <= 7; i++)
        printf("%d ",H[i]);

    printf("\n");
    return 0;
}
