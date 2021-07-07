/*
Linear probing only allows one item at each element.  There is no second dimension to look.  Linear probing is an example of open addressing.
Open addressing collision resolution methods allow an item to put in a different spot other than what the hash function dictates.  Aside from linear
probing, other open addressing methods include quadratic probing and double hashing.  With hash tables where collision resolution is handled via
open addressing, each record actually has a set of hash indexes where they can go.  If the first location at the first hash index is occupied, it goes to
the second, if that is occupied it goes to the third, etc.  The way this set of hash indexes is calculated depends on the probing method used.
*/

#include <iostream>
#define SIZE 10

using namespace std;

template <class T>
void printIt(T& vec, int n, string s) {
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }

    cout << "]" << endl;
}

int hashIt(int key){
    return key % SIZE;
}

int linearProbe(int H[], int key){
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != 0){
        i++;
    }
    return (idx + i) % SIZE;
}

void insertIt(int H[],int key){
    int idx = hashIt(key);
    if (H[idx] != 0){
        idx = linearProbe(H,key);
    }
    H[idx] = key;
}

int searchIt(int H[],int key){
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != key) {
        i++;
        if (H[(idx + i) % SIZE] == 0){
            return -1;
        }
    }
    return (idx + i) % SIZE;
}

int main() {
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29,35};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "**** linear probing ****\n";
    printIt(A,n,"array");

    // hash table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        insertIt(HT,A[i]);
    }

    printIt(HT, SIZE, "hash table");

    int index = searchIt(HT,25);
    cout << "key found at: " << index << endl;

    index = searchIt(HT,35);
    cout << "key found at: " << index << endl;

    return 0;
}
