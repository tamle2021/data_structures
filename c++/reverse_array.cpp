/*



**** reverse array ****

*/
#include<stdio.h>
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
    printf("elements: ");

    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);

    cout << "\n";
}

void swapIt(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseIt(struct Array *arr) {
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    // copy back to A array
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void reverse1(struct Array *arr) {
    int i, j;

    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        swapIt(&arr->A[i],&arr->A[j]);

}

int main() {
    cout << "**** reverse array ****\n";
    struct Array arr1 = {{11,15,19,24,34,41,49,53,59,67,71},12,11};
    struct Array arr2 = {{4,17,19,44,78},6,5};

    cout << "before reverse: " << endl;
    displayIt(arr1);
    cout << "after reverse: " << endl;
    reverseIt(&arr1);
    displayIt(arr1);

    cout << "before reverse: " << "\n";
    displayIt(arr2);
    cout << "after reverse: " << "\n";
    reverse1(&arr2);
    displayIt(arr2);

    return 0;

}
