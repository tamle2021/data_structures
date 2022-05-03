/*



**** get set max min array ****

*/
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

int getIt(struct Array arr,int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];

    return -1;
}

void setIt(struct Array *arr,int index,int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int findMax(struct Array arr) {
    int max1 = arr.A[0];
    int i;

    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] > max1)
            max1 = arr.A[i];
    }

    return max1;
}

int findMin(struct Array arr) {
    int min1 = arr.A[0];
    int i;

    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] < min1)
            min1 = arr.A[i];
    }

    return min1;
}

int sum(struct Array arr) {
    int s = 0;
    int i;

    for (i = 0; i < arr.length; i++)
        s += arr.A[i];

    return s;
}

float average(struct Array arr) {
    return (float)sum(arr) / arr.length;
}

int main() {
    cout << "**** get set max min array ****\n";
    struct Array arr1={{7,11,13,21,29,44,51,62,77,81,89},12,11};
    int getIndex = 4;
    int num1 = 76;

    displayIt(arr1);
    cout << "index " << getIndex << ": " << getIt(arr1,getIndex) << endl;
    printf("sum: %d\n",sum(arr1));

    cout << "set " << num1 << ": " << "\n";
    setIt(&arr1,9,num1);
    displayIt(arr1);

    return 0;
}


