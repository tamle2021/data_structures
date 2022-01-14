/*
Demonstrate order of execution on call stack when call recursive and print after.

**** head recursion ****

*/

#include <stdio.h>
#include <iostream>

using namespace std;

void function1(int n) {
    if (n > 0) {
        function1(n-1);
        printf("%d ",n);
    }
}

int main() {
    cout << "**** head recursion ****\n";
    int x = 7;

    function1(x);
    return 0;
}

