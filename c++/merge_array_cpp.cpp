/*



**** merge array c++ implementation ****

*/
#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
private:
    // int* arr;
    // int size;
    // int length;

public:
    int* arr;
    int size;
    int length;
    Array(int size,int length) {
        this->size = size;
        this->length = length;
        arr = new int [size];
    }

    int getIt(int index) {
        if (index >= 0 && index < length) {
            return arr[index];
        }
    }

    void setIt(int index,int x) {
        if (index >= 0 && index < length) {
            arr[index] = x;
        }
    }

    void displayIt(int* arr,int length) {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    Array mergeIt(Array& B) {
        Array C(length + B.length,length + B.length);
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < length && j < B.length) {
            if (arr[i] < B.getIt(j)){
                C.setIt(k++,arr[i++]);
            }
            else {
                C.setIt(k++,B.getIt(j++));
            }
        }

        // copy left-over elements
        for (; i < length; i++) {
            C.setIt(k++,arr[i]);
        }
        for (; j < B.length; j++) {
            C.setIt(k++,B.getIt(j));
        }

        return C;
    }

    ~Array() {
        delete[] arr;
    }
};

int main() {
    cout << "**** merge array c++ implementation ****\n";
    Array arr1(10,6);
    Array arr2(10,6);

    arr1.arr  = {new int[6]{2,4,6,8,10,19}};
    arr2.arr = {new int[6]{3,6,12,24,31,44}};

    cout << "array1: ";
    for (int i = 0; i < arr1.length; i++)
        cout << arr1.arr[i] << " ";
    cout << "\n";

    cout << "array2: ";
    for (int i = 0; i < arr2.length; i++)
        cout << arr2.arr[i] << " ";
    cout << "\n";

    //displayIt(X.arr,X.length);

    Array arr3 = arr1.mergeIt(arr2);
    cout << "result: ";
    for (int i = 0; i < arr3.length; i++)
        cout << arr3.arr[i] << " ";

    return 0;
}
