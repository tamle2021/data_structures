/*
Double hashing is a collision resolving technique in open addressed hash table.  Double hashing utilizes idea of applying second
hash function to key when collision occurs.  First hash function can be h1(key) = key % table size.  Second hash function can be
h2(key) = prime - (key % prime) where prime is a prime number smaller than table size.

**** double hashing ****

*/
#include <iostream>
#define SIZE 10
#define PRIME 7

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

int secondHash(int key){
    return PRIME - (key % PRIME);
}

int doubleHash(int H[],int key) {
    int idx = hashIt(key);
    int i = 0;
    while (H[(hashIt(idx) + i * secondHash(idx)) % SIZE] != 0) {
        i++;
    }
    return (idx + i * secondHash(idx)) % SIZE;
}

void insertIt(int H[],int key) {
    int idx = hashIt(key);

    if (H[idx] != 0) {
        idx = doubleHash(H,key);
    }

    H[idx] = key;
}

int searchIt(int H[],int key) {
    int idx = hashIt(key);
    int i = 0;

    while (H[(hashIt(idx) + i * secondHash(idx)) % SIZE] != key) {
        i++;
        int hSize = sizeof(H) / sizeof(H[0]);
        // check if end of hash array
        if (i > hSize)
            return -1;

        if (H[(hashIt(idx) + i * secondHash(idx)) % SIZE] == 0) {
            return -1;
        }

    }
    return (hashIt(idx) + i * secondHash(idx)) % SIZE;
}

int main() {
    // can't has zero
    cout << "**** double hashing ****\n";
    int A[] = {44,5,7,11,22,93,9,-6,0};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A,n,"array");

    // hash table
    int HT[10] = {0};
    for (int i = 0; i < n; i++) {
        insertIt(HT,A[i]);
    }
    printArray(HT,SIZE,"hash table");

    int index = searchIt(HT,5);
    cout << "search key 5 --- key found at index: " << index << endl;

    index = searchIt(HT,21);
    cout << "search key 21 --- key found at: " << index << endl;

    index = searchIt(HT,11);
    cout << "search key 11 --- key found at: " << index << endl;

    return 0;
}
