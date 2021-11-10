/*


**** merge sort c++ implementation ****
*/
#include <iostream>

using namespace std;

template <class T>
void printIt(T& vec,int n,string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void mergeIt(int x[],int y[],int z[],int m,int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (x[i] < y[j]) {
            z[k++] = x[i++];
        }
        else {
            z[k++] = y[j++];
        }
    }
    while (i < m) {
        z[k++] = x[i++];
    }
    while (j < n) {
        z[k++] = x[j++];
    }
}

void mergeSingle(int A[],int low,int mid,int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

int main() {
    cout << "**** merge sort c++ implementation *****\n";
    // arrays have to be sorted first
    int A[] = {-6,3,5,14,21,44,92,212};
    int m = sizeof(A) / sizeof(A[0]);
    printIt(A,m,"A");

    int B[] = {-5,0,1,20,29,44,99,102};
    int n = sizeof(B) / sizeof(B[0]);
    printIt(B,n,"B");

    int r = m + n;
    int C[r];
    mergeIt(A, B, C, m, n);

    // print function does not work for variable length array C
    cout << "sorted array" << ": [" << flush;
    for (int i = 0; i < r; i++) {
        cout << C[i] << flush;
        if (i < r - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
    cout << endl;

    int D[] = {2,43,55,81,0,4,17,61};
    cout << "**** merge single array ****\n";
    printIt(D, sizeof(D) / sizeof(D[0]),"d array");
    mergeSingle(D,0,3,7);
    printIt(D,sizeof(D) / sizeof(D[0]),"sorted d array");

    return 0;
}
