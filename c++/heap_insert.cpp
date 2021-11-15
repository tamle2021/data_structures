/*
A max-heap is a complete binary tree in which value in each internal node is greater than or equal to the values in children of
that node. Mapping the elements of a heap into an array is trivial.  For instance, if a node is stored at index k, then its left child is stored
at index 2k + 1 and its right child at index 2k + 2.

**** heap insert c++ implementation ****
*/
#include <iostream>
#include <vector>

using namespace std;

void insertA(int A[],int n){
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

// stl vector-based
void insertIt(vector<int>& vec, int key){
    // insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);

    // rearrange elements; indices are not dry
    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    vec[i] = key;
}

template <class T>
void printIt(T& vec,int n) {
    cout << "heap: [" << flush;
    for (int i = 0; i < n; i++){
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}


int main() {
    cout << "**** heap insert c++ implementation ****\n";
    int a[] = {35,24, 0,-7,13,9,44,23,101, 29,71};
    cout << "before max heapify: \n";
    printIt(a,sizeof(a) / sizeof(a[0]));
    insertA(a,10);
    cout << "after max heapify: \n";
    printIt(a,sizeof(a) / sizeof(a[0]));
    cout << endl;

    // stl-based
    vector<int> v = {44,99,0,-41,13, 9,75, 21, 2,11};
    cout << "**** heapify with insert ****\n";
    cout << "before heapify: \n";
    printIt(v, v.size());
     // reserve space for 20 elements
    v.reserve(20);

    cout << "after heapify: \n";
    insertIt(v,87);
    printIt(v, v.size());

    return 0;
}
