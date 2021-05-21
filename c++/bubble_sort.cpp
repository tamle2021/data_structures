/*
Bubble Sort is a sorting algorithm that works by repeatedly swapping the adjacent elements if they
are in wrong order.
example:
first pass:
( 5 1 4 2 8 ) --> ( 1 5 4 2 8 ) Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) -->  ( 1 4 5 2 8 ) Swap since 5 > 4
( 1 4 5 2 8 ) -->  ( 1 4 2 5 8 ) Swap since 5 > 2
( 1 4 2 5 8 ) --> ( 1 4 2 5 8 ) Now, since these elements are already in order (8 > 5), algorithm does not
swap them.
second pass:
(1 4 2 5 8) --> (1 4 2 5 8)
(1 4 2 5 8) --> (1 2 4 5 8) Swap since 4 > 2
(1 2 4 5 8) --> (1 2 4 5 8)
(1 2 4 5 8) -->  (1 2 4 5 8)
Now, the array is already sorted, but algorithm does not know if it is completed. The algorithm needs
one whole pass without any swap to know it is sorted.
third pass:
(1 2 4 5 8) --> (1 2 4 5 8)
(1 2 4 5 8) --> (1 2 4 5 8)
(1 2 4 5 8) --> (1 2 4 5 8)
(1 2 4 5 8) --> (1 2 4 5 8)

minimum time: O(n)
max time: O(n^2)
adaptive & stable
*/
#include <iostream>

using namespace std;

template <class T>
void printArray(T& vec,int n,string s) {
    cout << s << "[" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int* x,int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int A[],int n){
    int flag = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (A[j] > A[j+1]){
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0){
            return;
        }
    }
}

int main() {
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11,-99,101,2};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "*****bubble sort*****\n" << endl;
    cout << "---before sort---\n";
    printArray(A,n,"");

    bubbleSort(A,n);
    cout << "---after sort---\n";
    printArray(A,n,"");

    return 0;
}
