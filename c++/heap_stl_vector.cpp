/*
In computer science, a heap is a type of tree data structure that satisfies the heap property.  Heaps are useful when one needs to
remove the item with the highest or lowest value.  In a max-heap, the value of each item is less than or equal to the value of its parent,
with the maximum value item at the root.  In a min-heap, the value of each item is greater than or equal to the value of its parent, with
the minimum value item at the root.

**** create heap using stl vector ****
*/
#include <iostream>
#include <vector>

using namespace std;

void insertIt(vector<int>& vec,int key) {
    // insert key at end
    auto i = vec.size();
    vec.emplace_back(key);

    // rearrange elements has O(log n) time
    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    vec[i] = key;
}

void insertInPlace(int A[],int n) {
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void createHeap1(vector<int>& vec,int A[],int n) {
    // O(n log n)
    for (int i = 0; i < n; i++) {
        insertIt(vec,A[i]);
    }
}

void createHeap2(int A[],int n) {
    for (int i = 0; i < n; i++) {
        insertInPlace(A,i);
    }
}

template <class T>
void printIt(T& vec,int n,char c[]) {
    cout << c << " [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << " " << flush;
        }
    }
    cout << "]" << endl;
}

int main() {
    cout << "**** create heap using stl vector ****\n";
    cout << "before heap: \n";
    int array1[] = {7,25,4,0,11,-19,44,105};
    printIt(array1,sizeof(array1) / sizeof(array1[0]),"array1:");

    vector<int> v;
    createHeap1(v,array1,sizeof(array1) / sizeof(array1[0]));
    printIt(v,v.size(),"after create heap using vector:");

    createHeap2(array1,sizeof(array1) / sizeof(array1[0]));
    printIt(array1,sizeof(array1) / sizeof(array1[0]),"after create heap using in-place insert:");

    return 0;
}
