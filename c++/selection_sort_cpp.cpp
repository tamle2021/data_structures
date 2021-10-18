/*
Selection sort works by first starting at the beginning array of index 0 and traverses the entire array comparing each value
with the current index.  If the index is smaller than the current index, then that index is saved. Once the loop has traversed all data
elements and if smaller value than current index is found, a swap is made between the current index and the index where the smaller
value was found. The current index is incremented to index 1 and the process repeats.

time complexity: O(n^2)

*/
#include <iostream>

using namespace std;

template <class T>
void printIt(T& vec, int n, string s) {
    cout << s << " [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << " " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int A[],int n) {
    for (int i = 0; i < n - 1; i++) {
        int j;
        int k;
        for (j = k = i; j < n; j++) {
            if (A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int main() {
    cout << "**** selection sort c++ implementation ****\n";
    int A[] = {25,2,3,99,-44,12,62,11,101,8, 0, 45};
    int n = sizeof(A) / sizeof(A[0]);
    printIt(A,n,"before sort: ");

    selectionSort(A,n);
    printIt(A,n,"after sort: ");

    return 0;
}
