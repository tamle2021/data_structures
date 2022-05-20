/*



**** merge array ****

*/
#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct Array {
    int A[12];
    int size;
    int length;
};

void displayIt(struct Array arr) {
    int i;

    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);

    cout << "\n";
}

struct Array* merge1(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    //  copy left-over elements
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 12;

    return arr3;
}

int main() {
    cout << "**** merge array ****\n";
    struct Array arr1={{4,11,17,22,33,67},10,6};
    struct Array arr2={{5,14,19,25,31,52},10,6};
    struct Array *arr3;

    cout << "array1: ";
    displayIt(arr1);
    cout << "array2: ";
    displayIt(arr2);

    arr3 = merge1(&arr1,&arr2);
    cout << "result: ";
    displayIt(*arr3);
    return 0;
}




