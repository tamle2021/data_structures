/*

**** recursive merge sort ****
*/
#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

void mergeIt(int A[],int l,int mid,int h) {
    int i = l, j = mid + 1, k = l;
    int B[100];

    while(i <= mid && j <= h) {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for(; j <= h; j++)
        B[k++] = A[j];

    for(i = l; i <= h; i++)
        A[i] = B[i];
}

void mergeSort(int A[],int l,int h) {
    int mid;

    if (l < h) {
        mid = (l + h) / 2;
        mergeSort(A,l,mid);
        mergeSort(A,mid + 1,h);
        mergeIt(A,l,mid,h);
    }
}

int main() {
    cout << "**** recursive merge sort ****\n";
    int A[]={14,22,9,34,2,55,17,92,15,3,-3,0},n=12,i;

    cout << "before merge sort: " << endl;
    for (i = 0; i < 12; i++)
        cout << A[i] << " ";

    cout << "\n";
    mergeSort(A,0,11);

    cout << "after merge sort: \n";
    for (i = 0; i < 12; i++)
        printf("%d ",A[i]);

    printf("\n");
    return 0;
}
