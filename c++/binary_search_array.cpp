/*


**** binary-search array ****

*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Array {
    int A[12];
    int size;
    int length;
};

void displayIt(struct Array arr) {
    int i;
    printf("elements: ");

    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);

    cout << endl;
}

void swapIt(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int binarySearch(struct Array arr,int key) {
    int l,mid,h;
    l = 0;
    h = arr.length - 1;

    while(l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int recursiveBinarySearch(int a[],int l,int h,int key) {
    int mid = 0;

    if (l <= h) {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return recursiveBinarySearch(a,l,mid - 1,key);
    }
    else
        return recursiveBinarySearch(a,mid + 1,h,key);

    return -1;
}

int main() {
    cout << "**** binary-search array ****\n";
    struct Array arr1={{4,22,71,37,80,-8,11,41,72,25,3},12,11};
    int num1 = 14;
    int num2 = 25;
    int n = sizeof(arr1.A) / sizeof(arr1.A[0]);
    // sort array
    sort(arr1.A,arr1.A + n);

    displayIt(arr1);
    printf("num1: %d\nresult1 index: %d\n",num1,binarySearch(arr1,num1));
    cout << "num2: " << num2 << "\nresult2 index: " << binarySearch(arr1,num2);

    return 0;
}
