/*

**** display linked list c++ implementation
*/


#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

int main() {
    cout << "**** display linked list c++ implementation ****\n";
    int A[] = {31,51,17,14,111,0,-7};
    Node* head = new Node;

    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // create linked list
    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++) {
        // create temporary node
        temp = new Node;

        // populate node
        temp->data = A[i];
        temp->next = nullptr;
        // last's next points to temp
        last->next = temp;
        last = temp;
    }

    // display Linked List
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " " << flush;
        p = p->next;
    }

    return 0;
}
