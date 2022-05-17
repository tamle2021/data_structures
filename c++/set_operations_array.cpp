/*



**** set operations on array ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void displayIt(struct Array arr) {
    int i;

    for(i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
}

struct Array* unionIt(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    // clean-up operations
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* intersectionIt(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* difference(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main() {
    cout << "**** set operations on array ****\n";
    struct Array arr1={{4,11,14,25,31,41},10,6};
    struct Array arr2={{9,11,34,41,52,63},10,6};
    struct Array *arr3;
    struct Array *arr4;

    cout << "array1: ";
    displayIt(arr1);

    cout << "\narray2: ";
    displayIt(arr2);

    arr3 = unionIt(&arr1,&arr2);
    cout << "\nunion: ";
    displayIt(*arr3);

    arr4 = intersectionIt(&arr1,&arr2);
    cout << "\nintersection: ";
    displayIt(*arr4);

    return 0;
}
