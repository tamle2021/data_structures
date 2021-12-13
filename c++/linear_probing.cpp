/*
Linear probing is a scheme to resolve collisions in hash tables and implements data structures for maintaining a collection
of key-value pairs to look up value associated with given key.  Along with quadratic probing and double hashing, linear probing is a form
of open addressing. In these schemes, each cell of a hash table stores a single key-value pair. When the hash function causes a
collision by mapping a new key to a cell of hash table that is already occupied by another key, linear probing
searches table for the closest following free location and inserts new key there.

**** linear probing ****

*/

#include <stdio.h>
#include <iostream>
#define SIZE 10

using namespace std;

int hashIt(int key) {
    return key % SIZE;
}

int probe(int H[],int key) {
    int index = hashIt(key);
    int i = 0;

    while (H[(index + i) % SIZE] != 0)
        i++;

    return (index + i) % SIZE;
}

void insertIt(int H[],int key) {
    int index = hashIt(key);
    if (H[index] != 0)
        index = probe(H,key);

    H[index] = key;
}

int searchIt(int H[],int key) {
    int index = hashIt(key);
    int i = 0;

    for (i = 0; i < sizeof(H) / sizeof(H[0]); i++) {
        if (H[(index + i) % SIZE] == key)
            return (index + i) % SIZE;
    }

    // -1 for index not found
    return -1;
}

int main() {
    int value1 = 44;
    int value2 = 252;
    int hashTable[15] = {0};
    insertIt(hashTable,12);
    insertIt(hashTable,25);
    insertIt(hashTable,35);
    insertIt(hashTable,26);
    insertIt(hashTable,11);
    insertIt(hashTable,44);
    insertIt(hashTable,-7);

    cout << "**** linear probing ****\n";
    cout << "searching value: " << value1 << endl;
    cout << "found at position => " << searchIt(hashTable,value1) << "\n";

    cout << "searching value: " << value2 << endl;
    cout << "found at position => " << searchIt(hashTable,value2) << "\n";

    return 0;
}
