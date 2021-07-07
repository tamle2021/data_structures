/*
Linear probing is a scheme in computer programming for resolving collisions in hash tables and data structures for maintaining a collection of
key-value pairs and looking up the value associated with a given key.  Along with quadratic probing and double hashing, linear probing is a
form of open addressing. In these schemes, each cell of a hash table stores a single key-value pair. When the hash function causes a collision
by mapping a new key to a cell of the hash table that is already occupied by another key, linear probing searches the table for the closest
following free location and inserts the new key there.
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

void Insert(int H[],int key) {
    int index = hashIt(key);
    if (H[index] != 0)
        index = probe(H,key);

    H[index] = key;
}

int Search(int H[],int key) {
    int index = hashIt(key);
    int i = 0;

    while (H[(index + i) % SIZE] != key)
        i++;

    return (index + i) % SIZE;
}

int main() {
    int HT[10] = {0};
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);
    Insert(HT,11);
    Insert(HT,44);

    cout << "**** linear probing ****\n";
    printf("\nkey found at position: %d\n",Search(HT,44));

    return 0;
}
