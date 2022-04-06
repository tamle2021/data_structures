/*



**** insertion sort ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*void swapIt(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}*/

void sortIt(int A[],int n) {
    int i,j,x;

    for (i = 1; i < n; i++) {
        j = i - 1;
        x = A[i];

        // shifting
        while (j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = x;
    }
}

int main() {
    cout << "**** insertion sort ****\n";
    int A[] = {11,13,7,12,0,16,9,24,5,10,3};
    int n = 11;

    cout << "before sort: " << endl;
    for (long long unsigned i = 0; i < sizeof(A) / sizeof(A[0]); i++ )
        cout << A[i] << " ";
    cout << "\n";

    cout << "after sort: \n";
    sortIt(A,n);
    for (long long unsigned i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        printf("%d ",A[i]);

    printf("\n");

    return 0;
}
