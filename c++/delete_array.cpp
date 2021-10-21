/*

**** delete from array ****
*/
#include <stdio.h>
#include <iostream>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void display(struct Array arr) {
    int i;
    printf("\nelements are: \n");
    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
    }

int deleteIt(struct Array *arr,int index) {
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i+1];

        arr->length--;
        return x;
    }

    return 0;
}

int main() {
    struct Array arr1 = {{22,31,1,44,62,9},11,67};
    cout << "**** delete from array ****\n";
    printf("element deleted: %d",deleteIt(&arr1,1));

    display(arr1);
    return 0;
}
