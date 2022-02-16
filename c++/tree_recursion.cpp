/*
Tree recursion is when there is more than one recursive call in the recursive case.  It creates a tree-like
diagram when tracing through call stack.


**** tree recursion ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

void func1(int n) {
    if (n > 0) {
        printf("%d ",n);
        func1(n - 1);
        func1(n - 1);
    }
}

int main() {
    cout << "**** tree recursion ****" << endl;
    func1(5);

    return 0;
}
