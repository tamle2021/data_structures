/*
number of comparisons => (n * (n-1)) / 2 = O(n^2)
number of swaps => O(n^2)
adaptive & stable
*/
#include <iostream>

using namespace std;

template <class T>
void printArray(T& vec,int n,string s){
    cout << s << "[" << flush;
    for (int i = 0; i < n; i++){
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void insertionSort(int A[],int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = A[i];
        while (j > -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main() {
    int arr[] = {3,125,-99,133,19, 17, 15, 13, 11, 9, 7, 5, 3,-2,101,1,55};
    cout << "*****insertion sort*****" << endl;
    cout << "before sort: \n";
    printArray(arr, sizeof(arr) / sizeof(arr[0]), "");

    insertionSort(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "after sort: \n";
    printArray(arr, sizeof(arr) / sizeof(arr[0]), "");

    return 0;
}
