/*
Global variable is a variable declared outside of a function.

**** global variable ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int x = 0;

int func1(int n) {
    if (n > 0) {
        x = x + 2;
        return func1(n - 1) + x;
    }

    return 0;
}

int main() {
    cout << "**** global variable ****\n";
    int r;
    cout << "first call: ";
    r = func1(8);
    printf("%d\n",r);

    cout << "second call: ";
    r = func1(8);
    printf("%d\n",r);

    cout << "third call: ";
    r = func1(8);
    cout << r << endl;

    return 0;
}
