/*



**** iterative merge sort c++ implementation ****

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
    int B[high + 1];

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= high){
        B[k++] = A[j++];
    }

    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void iterativeMergeSort(int A[],int n) {
    int p;

    for (p = 2; p <= n; p = p * 2) {
        for (int i = 0; i + p - 1 < n; i = i + p) {
            int low = i;
            int high = i + p - 1;
            int mid = (low + high) / 2;

            mergeIt(A,low,mid,high);
        }
    }

    if (p / 2 < n) {
        mergeIt(A,0,p / 2 - 1,n - 1);
    }
}

int main() {
    cout << "**** iterative merge sort c++ implementation ****" << endl;
    int A[] = {92,24,0,41,18,7,52,-9,71,11};
    int len = sizeof(A) / sizeof(A[0]);

    printIt(A,len,"before sort: ");
    iterativeMergeSort(A,len);
    printIt(A,len,"after sort: ");

    return 0;
}
