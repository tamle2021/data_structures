/*



**** searching array ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

struct Array {
    int A[11];
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

int linearSearch(struct Array *arr,int key) {
    int i;

    for (i = 0; i < arr->length; i++) {
        // swapy with first element
        if (key == arr->A[i]) {
            swapIt(&arr->A[i],&arr->A[0]);
            return i;
        }
    }

    return -1;
}

int main() {
    cout << "**** searching array ****\n";
    struct Array arr1={{0,27,-4,12,44,101,21,53,9,64},11,10};
    int num1 = 13;
    int num2 = 12;

    displayIt(arr1);
    printf("searching1: %d\nresult1 index: %d\n",num1,linearSearch(&arr1,num1));
    cout << "searching2: " << num2 << "\nresult2 index: " << linearSearch(&arr1,num2) << endl;

     cout << "after swap: \n";
     displayIt(arr1);

    return 0;
}
