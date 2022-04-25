/*



**** insert array ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

struct Array {
    int A[15];
    int size;
    int length;
};

void displayIt(struct Array arr) {
    int i;

    printf("\nelements: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);

    cout << endl;
}

void appendIt(struct Array *arr,int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void insertIt(struct Array *arr,int index,int x) {
    int i;

    if (index >= 0 && index <= arr->length) {
        // shift elements by one to right
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];

        arr->A[index] = x;
        arr->length++;
    }
}

//  inserting and appending in array
int main() {
    cout << "**** insert array ****";
    struct Array arr1={{2,3,4,5,6},12,5};
    int num1 = 10;
    int num2 = 12;

    displayIt(arr1);
    cout << "append " << num1 << " at end: ";
    appendIt(&arr1,num1);
    displayIt(arr1);
    cout << "insert " << num2 << " at beginning: ";
    insertIt(&arr1,0,num2);
    displayIt(arr1);

    return 0;
}

