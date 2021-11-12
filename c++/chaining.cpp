/*

**** hashing & chaining ****
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header_files/chains.h"

using namespace std;

int hashIt(int key) {
    return key % 10;
}

void insertIt(struct Node *H[],int key) {
    int index = hashIt(key);
    sortedInsert(&H[index],key);
}

int main() {
    cout << "**** hashing & chaining ****\n";
    struct Node *hashTable[10];
    struct Node *temp1, *temp2;
    int i;
    int testValue1 = 23;
    int testValue2 = 8;

    for(i = 0; i < 10; i++)
        hashTable[i] = NULL;

    insertIt(hashTable,8);
    insertIt(hashTable,29);
    insertIt(hashTable,51);
    insertIt(hashTable,0);
    insertIt(hashTable,-6);

    cout << "searching " << testValue1 << ": ";
    temp1 = searchIt(hashTable[hashIt(testValue1)],testValue1);
    if (temp1 == NULL)
        cout << "no value found...." << endl;
    else
        printf("value found => %d ",temp1->data);

    cout << "searching " << testValue2 << ": ";
    temp2 = searchIt(hashTable[hashIt(8)],8);
    if (temp2 == NULL)
        cout << "no value found...." << endl;
    else
        printf("value found => %d ",temp2->data);


    return 0;
}
