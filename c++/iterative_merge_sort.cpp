/*



**** iterative merge sort ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void mergeIt(int A[],int l,int mid,int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100];

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i <= mid; i++)
        B[k++] = A[i];

    for(; j <= h; j++)
        B[k++] = A[j];

    for(i = l;i <= h; i++)
        A[i] = B[i];
}

void sortIt(int A[],int n) {
    int p,l,h,mid,i;

    for (p = 2; p <= n; p = p * 2) {
        for (i = 0; i + p - 1 < n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            mergeIt(A,l,mid,h);
        }

        if (n - i > p / 2) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            mergeIt(A,l,mid,n-1);
        }
    }

    if (p / 2 < n)
        mergeIt(A,0,p / 2 - 1,n - 1);

}

int main() {
    cout << "**** iterative merge sort ****\n";
    int A[] = {7,54,-5,0,12,23,51,101,44,3};
    int n = 10;
    long long unsigned len = sizeof(A) / sizeof(A[0]);

    cout << "before sort: " << endl;
    for (long long unsigned i = 0; i < len; i++ )
        cout << A[i] << " ";

    cout << "\n";

    cout << "after sort: " << endl;
    sortIt(A,n);
    for (long long unsigned i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}
