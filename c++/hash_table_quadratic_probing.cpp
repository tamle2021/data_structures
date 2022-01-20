/*
Hash table is a data structure used to store key-value pairs. Hash function is used to compute an index into array, for which an element
will be inserted or searched in hash table. Quadratic probing is a collision resolving technique in open addressed hash table. It
operates by taking hash index and adding successive values of an arbitrary quadratic polynomial until an open slot is found.


**** hash table quadratic probing ****

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

int hashIt(int key) {
    return key % SIZE;
}

int quadraticProbe(int H[],int key) {
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + i * i) % SIZE] != 0) {
        i++;
    }
    return (idx + (i * i)) % SIZE;
}

void insertIt(int H[],int key) {
    int idx = hashIt(key);

    if (H[idx] != 0) {
        idx = quadraticProbe(H,key);
    }
    H[idx] = key;
}

int searchIt(int H[],int key) {
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + (i * i)) % SIZE] != key) {
        i++;
        if (H[(idx + (i * i )) % SIZE] == 0) {
            return -1;
        }
    }
    return (idx + (i * i)) % SIZE;
}

int main() {
    // can't hash negative numbers correctly?
    cout << "**** hash table quadratic probing ****" << endl;
    int A[] = {11,22,30,45,3,25,43,74,18,44};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A,n,"array elements");

    // hash table
    int HT[10] = {0};
    for (int i = 0; i < n; i++) {
        insertIt(HT,A[i]);
    }
    printArray(HT,SIZE,"hash table");

    int index = searchIt(HT,30);
    cout << "search element 30 --- key found at: " << index << endl;

    index = searchIt(HT,35);
    cout << "search element 35 --- key found at: " << index << endl;

    return 0;
}
