/*




**** shell sort ****

*/
#include <stdio.h>
#include <stdlib.h>
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

// similar to insertion sort with modifications
void shellSort(int A[],int n) {
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int j = gap; j < n; j++) {
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp) {
                A[i + gap] = A[i];
                i = i - gap;
            }

            A[i + gap] = temp;
        }
    }
}

int main() {
    cout << "**** shell sort ****\n";
    int arr[] = {15,22,0,-9,29,93,7,52,21,104};
    int n = sizeof(arr) / sizeof(arr[0]);

    printIt(arr,n,"before sort: ");
    shellSort(arr,n);
    printIt(arr,n,"after sort: ");
    return 0;
}
