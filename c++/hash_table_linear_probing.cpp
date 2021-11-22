/*
Linear probing only allows one item at each element.  There is no second dimension to look.  Linear probing is an example of open
addressing.  Open addressing collision resolution methods allow an item to put in a different spot other than what the hash function
dictates.  Aside from linear probing, other open addressing methods include quadratic probing and double hashing.  With hash tables
where collision resolution is handled via open addressing, each record actually has a set of hash indexes where they can go.  If the
first location at the first hash index is occupied, it goes to the second, if that is occupied it goes to the third, etc.  The way this set of
hash indexes is calculated depends on the probing method used.

**** linear probing in hash table ****

*/

#include <iostream>
#define SIZE 10

using namespace std;

template <class T>
void printIt(T& vec,int n,string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n-1) {
            cout << " " << flush;
        }
    }

    cout << "]" << endl;
}

int hashIt(int key) {
    return key % SIZE;
}

int linearProbe(int H[], int key) {
    int idx = hashIt(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != 0) {
        i++;
    }
    return (idx + i) % SIZE;
}

void insertIt(int H[],int key) {
    int idx = hashIt(key);
    if (H[idx] != 0) {
        idx = linearProbe(H,key);
    }
    H[idx] = key;
}

int searchIt(int H[],int key) {
    int index = hashIt(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key) {
        i++;
        if (H[(index + i) % SIZE] == 0) {
            return -1;
        }
    }
    return (index + i) % SIZE;
}

int main() {
    // questionable hashing logic
    cout << "**** linear probing in hash table ****\n";
    printIt(A,n,"array");
    int A[] = {19,7,40,1,44,23,25,43,74,0,12};
    int n = sizeof(A) / sizeof(A[0]);
    int value1 = 25;
    int value2 = 35;

    // hash table
    int HT[15] = {0};
    for (int i = 0; i < n; i++) {
        insertIt(HT,A[i]);
    }

    printIt(HT,SIZE,"hash table");

    int index = searchIt(HT,value1);
    cout << "searching " << value1 << " => key found at " << index << endl;

    index = searchIt(HT,value2);
    cout << "searching " << value2 << " => key found at  " << index << endl;

    return 0;
}
