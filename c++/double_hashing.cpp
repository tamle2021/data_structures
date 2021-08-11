/*
Double hashing is a collision resolving technique in open addressed hash table.  Double hashing uses idea of applying a second hash function
to key when a collision occurs.  First hash function is typically hash1(key) = key % TABLE_SIZE.
Second hash function can be hash2(key) = PRIME - (key % PRIME) where PRIME is a prime number smaller than TABLE_SIZE.
*/
#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;

template <class T>
void printVector(T& vec,int n, string s){
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++){
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

int primeHash(int key){
    return PRIME - (key % PRIME);
}

int doubleHash(int H[],int key){
    int idx = hashIt(key);
    int i = 0;
    while (H[(hashIt(idx) + i * primeHash(idx)) % SIZE] != 0) {
        i++;
    }
    return (idx + i * primeHash(idx)) % SIZE;
}

void Insert(int H[],int key) {
    int idx = hashIt(key);

    if (H[idx] != 0) {
        idx = doubleHash(H, key);
    }
    H[idx] = key;
}

int searchKey(int H[], int key){
    int idx = hashIt(key);
    int i = 0;
    while (H[(hashIt(idx) + i * primeHash(idx)) % SIZE] != key){
        i++;
        if (H[(hashIt(idx) + i * primeHash(idx)) % SIZE] == 0){
            return -1;
        }
    }
    return (hashIt(idx) + i * primeHash(idx)) % SIZE;
}

int main() {
    cout << "**** double hashing ****\n";

    int A[] = {5,25,0,-5,15,35,95,22,101};
    int n = sizeof(A) / sizeof(A[0]);
    printVector(A,n,"array");

    // hash table
    int HT[10] = {0};
    for (int i = 0; i < n; i++) {
        Insert(HT,A[i]);
    }
    printVector(HT,SIZE,"hash table");

    cout << "search key 22\n";
    int index = searchKey(HT,22);
    cout << "key found at: " << index << endl;

    cout << "search key 44\n";
    index = searchKey(HT,44);
    cout << "key found at: " << index << endl;

    return 0;
}
