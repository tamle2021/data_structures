/*



**** heapify ****

*/
#include <iostream>

using namespace std;

template <class T>
void printIt(T& vec,int n,string s) {
    cout << s << ": " << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << " " << flush;
        }
    }

    cout << " " << endl;
}

void swapIt(int A[],int i,int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int deleteIt(int A[],int n) {
    // max element
    int x = A[0];
    A[0] = A[n - 1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < n - 1){
        // compare left and right children
        if (A[j] < A[j + 1]) {
            j = j + 1;
        }

        // compare parent and largest child
        if (A[i] < A[j]) {
            swapIt(A,i,j);
            i = j;
            j = 2 * i + 1;
        }
        else {
            break;
        }
    }

    return x;
}

void heapify1(int A[],int n) {
    // # of leaf elements: (n + 1) / 2, index of last leaf's parent = (n / 2) - 1
    for (int i = (n / 2) - 1; i >= 0; i--) {
        // left child for current i
        int j = 2 * i + 1;

        while(j < n - 1) {
            // compare left and right children of current i
            if (A[j] < A[j + 1]) {
                j = j + 1;
            }

            // compare parent and largest child
            if (A[i] < A[j]) {
                swapIt(A,i,j);
                i = j;
                j = 2 * i + 1;
            }
            else {
                break;
            }
        }
    }
}

int main() {
    // max heap
    cout << "**** heapify ****\n";
    int A[] = {11,3,12,30,0,34,91,55,12,62};
    printIt(A,sizeof(A) / sizeof(A[0]),"A");

    heapify1(A,sizeof(A) / sizeof(A[0]));
    printIt(A,sizeof(A) / sizeof(A[0]),"heapify A");
    cout << endl;

    int B[] = {3,17,15,71,0};
    printIt(B,sizeof(B) / sizeof(B[0]), "B");

    heapify1(B,sizeof(B) / sizeof(B[0]));
    printIt(B,sizeof(B) / sizeof(B[0]),"heapify B");

    return 0;
}
