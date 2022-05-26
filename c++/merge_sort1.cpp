/*



**** merge sort ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void swapIt(int &a,int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void displayIt(int *arr,int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
        cout << endl;
}

void merge1(int *arr,int l,int m, int r) {
    int i,j,k;
    // size of left and right sub-arrays
    int left = m - l + 1;
    int right = r - m;
    int leftArr[left], rightArr[right];
    // fill left and right sub-arrays
    for (i = 0; i < left; i++)
        leftArr[i] = arr[l + i];
    for (j = 0; j < right; j++)
        rightArr[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    // merge temp arrays to single array
    while (i < left && j < right) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }
    // copy left-over elements
    while (i < left) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < right) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr,int l,int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;
        // recursively call on smaller sections of array and then build back up
        // start on left side of tree first
        mergeSort(arr,l,m);
        mergeSort(arr,m + 1,r);
        // merge after returning
        merge1(arr,l,m,r);
    }
}

int main() {
    cout << "**** merge sort ****\n";
    int arr[] = {25,0,92,-9,44,1,3,37,52};
    int len = sizeof(arr) / sizeof(arr[0]);

   cout << "before sort: ";
   displayIt(arr,len);
   mergeSort(arr,0,len - 1);
   cout << "after sort: ";
   displayIt(arr,len);

   return 0;
}
