/*
minimum time: O(n)
max time: O(n^2)
adaptive & stable
*/
#include <iostream>

using namespace std;

template <class T>
void printArray(T& vec,int n,string s) {
    cout << s << ": [" << flush;
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
    printArray(A,n,"array:");

    bubbleSort(A,n);
    cout << "---after sort---\n";
    printArray(A,n,"array: ");

    return 0;
}
