/*
Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.  Insertion sort works similarly
as we sort cards in our hand in a card game.  We assume that the first card is already sorted then, we select an unsorted card. If the
unsorted card is greater than the card in hand, it is placed on the right otherwise, to the left. In the same way, other unsorted cards are
taken and put in their right place.

number of comparisons: (n * (n-1)) / 2 = O(n^2)
number of swaps: O(n^2)
best time: O(n)
worst time: O(n^2)
average time: O(n^2)
space complexity: O(1)

**** insertion sort c++ implementation ****

*/
#include <iostream>

using namespace std;

template <class T>
void printIt(T& vec,int n,string s) {
    cout << s << "[" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void insertIt(int A[],int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = A[i];

        while (j > -1 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = x;
    }
}

int main() {
     cout << "**** insertion sort c++ implementation ****" << endl;
    int arr[] = {3,125,-99,133,19,17,15,13,11,9,7,5,3,-2,101,1,55};

    cout << "before sort: \n";
    printIt(arr,sizeof(arr) / sizeof(arr[0]),"");

    insertIt(arr,sizeof(arr) / sizeof(arr[0]));
    cout << "after sort: \n";
    printIt(arr,sizeof(arr) / sizeof(arr[0]),"");

    return 0;
}
