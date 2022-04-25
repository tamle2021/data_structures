/*



**** is sorted ****

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

void displayIt(struct Array arr,int type) {
    int i;
    printf("\narray%d: ",type);

    for (i = 0; i < arr.length; i++)
        // cout << "test....";
        // printf("%d ",arr.A[i]);
        cout << arr.A[i] << " ";

    cout << endl;
}

int isSorted(struct Array arr) {
    int i;

    for(i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }

    return 1;
}

// checking if array is sorted
int main() {
    cout << "**** is sorted ****";
    struct Array arr1 = {{9,44,21,22,3,91,24,41,15},10,9};
    struct Array arr2 = {{4,5,6,7,8,9,10},8,7};

    displayIt(arr1,1);
    printf("is sorted: %d",isSorted(arr1));

    displayIt(arr2,2);
    printf("is sorted: %d",isSorted(arr2));

    return 0;
}
