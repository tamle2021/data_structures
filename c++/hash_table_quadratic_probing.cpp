/*
A hash table is a data structure used to store key-value pairs. Hash function is used to compute an index into array, for which an element will be
inserted or searched in hash table. Quadratic probing is a collision resolving technique in open addressed hash table. It operates by
taking the original hash index and adding successive values of an arbitrary quadratic polynomial until an open slot is found.
*/
#include <iostream>
#define SIZE 10

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

int hashIt(int key){
    return key % SIZE;
}

int QuadraticProbe(int H[],int key) {
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + i * i) % SIZE] != 0) {
        i++;
    }
    return (idx + (i * i)) % SIZE;
}

void Insert(int H[],int key) {
    int idx = hashIt(key);

    if (H[idx] != 0) {
        idx = QuadraticProbe(H,key);
    }
    H[idx] = key;
}

int searchKey(int H[],int key) {
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + (i * i)) % SIZE] != key){
        i++;
        if (H[(idx + (i * i )) % SIZE] == 0){
            return -1;
        }
    }
    return (idx + (i * i)) % SIZE;
}

int main() {
    cout << "**** hash table with quadratic probing ****" << endl;
    int A[] = {0,-7,26,30,45,23,97,25,43,74,19,29,88};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A,n,"array elements");

    // hash table
    int HT[13] = {0};
    for (int i = 0; i < n; i++) {
        Insert(HT,A[i]);
    }
    printArray(HT, SIZE,"hash table");

    cout << "search element 88\n";
    int index = searchKey(HT,88);
    cout << "key found at: " << index << endl;

    cout << "search element 35\n";
    index = searchKey(HT,35);
    cout << "key found at: " << index << endl;

    return 0;
}
