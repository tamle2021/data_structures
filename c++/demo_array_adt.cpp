/*
array abstract data type representation
*/
#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
public:
    Array(int size) {
        this->size = size;
        A = new int [size];
    }

    void create() {
        cout << "enter number of elements: " << flush;
        cin >> length;
        cout << "enter array elements: " << endl;
        for (int i = 0; i < length; i++) {
            cout << "array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }

    void display() {
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }

    ~Array() {
        delete[] A;
        cout << "\narray destroyed..." << endl;
    }
};

int main() {
    cout << "**** demo array adt ****\n";
    Array arr(22);
    arr.create();
    arr.display();

    return 0;
}
