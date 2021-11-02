/*
Quicksort is a sorting algorithm based on the divide and conquer approach where an array is divided into sub-arrays by selecting
a pivot element.  While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are
kept on left side and elements greater than pivot are kept on right side.


**** quick sort c++ implementation ****
*/

#include <iostream>

using namespace std;

template <class T>
void printIt(T& vec,int n,string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int* x,int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// quick sort using INT_MAX or infinity
int partitionA(int A[],int low,int high){
    int pivot = A[low];
    int i = low;
    int j = high;

    do {
        // increment i as long as elements are smaller/equal to pivot
        do {
            i++;
        } while (A[i] <= pivot);

        // decrement j as long as elements are larger than pivot
        do {
                j--;
        } while (A[j] > pivot);

        if (i < j) {
            swap(&A[i],&A[j]);
        }
    } while (i < j);

    swap(&A[low],&A[j]);

    return j;
}

void quickSortA(int A[],int low,int high) {
    if (low < high) {
        int j = partitionA(A,low,high);
        quickSortA(A,low,j);
        quickSortA(A,j+1,high);
    }
}

// last element is pivot + without using INT_MAX or infinity
int partitionLast(int A[],int low,int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j<=high - 1; j++){
        if (A[j] < pivot) {
            i++;
            swap(&A[i],&A[j]);
        }
    }

    swap(&A[i+1],&A[high]);

    return i + 1;
}

void quickSortLast(int A[],int low,int high) {
    if (low < high) {
        // A[p] in sorted position
        int p = partitionLast(A,low,high);
        // sort elements in range: A[low], A[p-1]
        quickSortLast(A,low,p-1);
        // sort elements in range: A[p+1], A[high]
        quickSortLast(A,p+1,high);
    }
}

// first element is pivot + without using INT_MAX or INFINITY
int partition(int A[],int low,int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && A[i] <= pivot) {
            i++;
        }
        while (A[j] >= pivot && j >= i) {
            j--;
        }
        if (j < i) {
            break;
        }
        else {
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[low],&A[j]);

    return j;
}

void quickSort(int A[],int low,int high) {
    if (low < high) {
        int p = partition(A,low,high);
        quickSort(A,low,p - 1);
        quickSort(A,p + 1,high);
    }
}

int main() {
    cout << "**** quick sort c++ implementation ****\n";
    cout << "using INT_MAX or infinity" << endl;
    int arrayA[] = {33,6,11,-4,99,23,44,21,0,3,32767};
    int n = sizeof(arrayA) / sizeof(arrayA[0]);

    printIt(arrayA,n - 1,"array a");
    quickSortA(arrayA,0,n - 1);
    printIt(arrayA,n - 1,"sorted array a");
    cout << endl;

    cout << "last element as pivot + without INT_MAX or infinity" << endl;
    int arrayB[] = {1,84,3,7,17,99,0,54,11,31};
    printIt(arrayB,sizeof(arrayB) / sizeof(arrayB[0]),"array b");

    quickSortLast(arrayB,0,sizeof(arrayB) / sizeof(arrayB[0]) - 1);
    printIt(arrayB,sizeof(arrayB) / sizeof(arrayB[0]), "sorted array b");
    cout << endl;

    cout << "first element as pivot + without INT_MAX or infinity" << endl;
    int arrayC[] = {8,0,13,77,7,2,-75,22,14,44,5,27,102,40};
    printIt(arrayC,sizeof(arrayC) / sizeof(arrayC[0]),"array C");

    quickSort(arrayC,0,sizeof(arrayC) / sizeof(arrayC[0]) - 1);
    printIt(arrayC,sizeof(arrayC) / sizeof(arrayC[0]),"sorted array C");

    return 0;
}
