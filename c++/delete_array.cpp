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

void displayIt(struct Array arr) {
    int i;
    // printf("\nelements: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
    }

int deleteIt(struct Array *arr,int index) {
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        // shifting elements left
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i+1];

        arr->length--;
        return x;
    }

    return 0;
}

int main() {
    cout << "**** delete array ****\n";
    struct Array arr1 = {{22,31,24,-7,1,0,44,62,9},10,9};
    int index1 = 1;
    cout << "before delete: ";
    displayIt(arr1);
    cout << endl;
    printf("delete element at index %d: \n",index1);
    deleteIt(&arr1,index1);

    cout << "after delete: ";
    displayIt(arr1);

    return 0;
}
