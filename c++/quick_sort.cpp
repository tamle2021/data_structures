/*
Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays. A large array is
partitioned into two arrays, one of which holds values smaller than specified value, say pivot, based on which the partition is made,
and another array holds values greater than the pivot value.

Quick sort partitions an array and then makes two recursive calls to sort the two resulting sub-arrays. This algorithm is quite efficient
for large-sized data sets as its average and worst-case complexity are O(n^2).


**** quick sort ****
*/
#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

void swap(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[],int l,int h) {
    int pivot = A[l];
    int i = l,j = h;

    do {
        do {
            i++;
        }
        while(A[i] <= pivot);

        do{
            j--;
        } while(A[j] > pivot);

        if (i < j)
            swap(&A[i],&A[j]);
    } while(i < j);

    swap(&A[l],&A[j]);
    return j;
}

void quickSort(int A[],int l,int h) {
    int j;

    if (l < h) {
        j = partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j + 1,h);
    }
}

int main() {
    cout << "**** quick sort ****\n";
    int A[] = {9,14,77,0,-4,25,30,59,2,45,12,23},numElem = 12,i;

     cout << "before sort: " << endl;
     for (i = 0; i < numElem; i++)
        cout << A[i] << " ";

    cout << "\nafter sort: \n";
    quickSort(A,0,numElem);
    for(i = 0; i < numElem; i++)
        printf("%d ",A[i]);

    printf("\n");
    return 0;
}
