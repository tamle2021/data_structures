/*



**** demo array abstract data type ****

*/
#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

public:
    // constructor
    Array(int size) {
        this->size = size;
        A = new int [size];
    }

    void create() {
        cout << "enter number of elements: " << flush;
        cin >> length;
        cout << "enter array elements: " << endl;
        for (int i = 0; i < length; i++) {
            cout << "element " << i << " : " << flush;
            cin >> A[i];
        }
    }

    void displayIt() {
        cout << "array elements: ";
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }

    ~Array() {
        delete []A;
        cout << "\narray destructor...." << endl;
    }
};

int main() {
    cout << "**** demo array abstract data type ****\n";
    Array arr(25);
    arr.create();
    arr.displayIt();

    return 0;
}
