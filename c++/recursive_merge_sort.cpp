/*



**** recursive merge sort ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
void swapIt(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}*/

void mergeIt(int A[],int l,int mid,int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100];

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void recursiveMergeSort(int A[],int l,int h) {
    int mid;

    if (l < h) {
        mid = (l + h) / 2;
        recursiveMergeSort(A,l,mid);
        recursiveMergeSort(A,mid + 1,h);
        mergeIt(A,l,mid,h);
    }
}

int main() {
    cout << "**** recursive merge sort ****\n";
    int A[] = {87,44,0,67,-4,12,11,29,3,6,99,101,21};
    int len = sizeof(A) / sizeof(A[0]);
    int i;

    cout << "before sort: \n";
    for (i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << "\n";

    cout << "after sort: \n";
    recursiveMergeSort(A,0,len - 1);
    for (i = 0; i < len; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}
