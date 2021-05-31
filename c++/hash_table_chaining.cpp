/*
*** Hashing ***
With direct addressing, the element with key k is placed in slot k. With hashing, this element is stored
in the slot h(k). This means that a hash function h(k) is used to compute the slot or index into the table
using the key. The hash function h maps the universe U into slots in the table T[0, 1, 2, . . .  m-1]
h: U => {0, 1, 2, . . . , m-1} where the size of the hash table m is much less than the size of the universe U.
Here the element with key k hashes to slot h(k).  The hash function is used to reduce the range of the
array indices to the size of the hash table.

Collision occurs if two keys map to the same slot in the hash table. One method of resolving collision is by
chaining as we would discuss next.

One method of handling collision in a hash table is by chaining. In chaining, one uses a linked list to manage
collision.  Elements that hash to the same slot are placed in a linked list and the slot in the hash table would
contain a pointer to the head of this hash table.
*/
#include <iostream>

using namespace std;

// linked list node
class Node{
public:
    int data;
	Node* next;
};

// hash table
class HashTable{
public:
	Node** HT;
	HashTable();
	int hash(int key);
	void insert(int key);
	int search(int key);
	~HashTable();
};

HashTable::HashTable() {
	HT = new Node* [10];
	for (int i=0; i<10; i++){
		HT[i] = nullptr;
	}
}

int HashTable::hash(int key) {
    // hashing negative numbers
	return abs(key % 10);
}

void HashTable::insert(int key) {
	int hIdx = hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = nullptr;
	// no nodes in the linked list
	if (HT[hIdx] == nullptr) {
		HT[hIdx] = t;
	}
	else {
		Node* p = HT[hIdx];
		Node *q=HT[hIdx];
		// traverse to find insert position
		while (p && (p->data < key)) {
			q=p;
			p = p->next;
		}
		// insert position is first
		if (q == HT[hIdx]) {
			t->next = HT[hIdx];
			HT[hIdx] = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int HashTable::search(int key) {
	int hIdx = hash(key);
	Node* p = HT[hIdx];
	while (p) {
		if (p->data == key){
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable() {
	for (int i = 0; i < 10; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int main() {
	int A[] = {16,12, 25, 39,6,122,5,68,75,99,101,0,77,-11};
	int n = sizeof(A) / sizeof(A[0]);
	HashTable h;
	for (int i=0; i < n; i++){
		h.insert(A[i]);
	}
	cout << "successful search: " << endl;
	int key = 6;
	int value = h.search(key);
	cout << "key => " << key << "   value => " << value << endl;
	cout << "\n" << "unsuccessful search: " << endl;
	key = 95;
	value = h.search(key);
	cout << "key => " << key << "   value => " << value << endl;

	cout << "\n???\n";
	key = -11;
	value = h.search(key);
	cout << "key => " << key << "   value => " << value << endl;

	cout << "\n?????\n";
	key = 66;
	value = h.search(key);
	cout << "key => " << key << "   value => " << value << endl;

	return 0;
}
