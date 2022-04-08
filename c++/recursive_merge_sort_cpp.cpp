/*




**** recursive merge sort c++ implementation ****

*/
#include <iostream>

using namespace std;

template <class T>
void printIt(T& vec,int n,string s) {
    cout << s << "" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << " " << flush;
        }
    }
    cout << "" << endl;
}

void mergeIt(int A[],int low,int mid,int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high+1];

    while (i <= mid && j <= high) {
        if (A[i] < A[j]){
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= high) {
        B[k++] = A[j++];
    }

    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void recursiveMergeSort(int A[],int low,int high) {
    if (low < high){
        // midpoint
        int mid = low + (high - low) / 2;

        // sort sub-lists
        recursiveMergeSort(A,low,mid);
        recursiveMergeSort(A,mid + 1,high);
        // merge sorted sub-lists
        mergeIt(A,low,mid,high);
    }
}

int main() {
    cout << "**** recursive merge sort c++ implementation ****\n";
    int A[] = {24,7,23,0,35,99,121,-4,3,29};
    int len = sizeof(A) / sizeof(A[0]);

    printIt(A,len,"before sort: \n");
    recursiveMergeSort(A,0,len - 1);
    printIt(A,len,"after sort: \n");

    return 0;
}

