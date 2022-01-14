/*
Demonstrate order of execution on call stack when print and call recursive after.

**** tail recursion ****

*/

#include <stdio.h>
#include <iostream>

using namespace std;

void function1(int n) {
    if(n > 0) {
        printf("%d ",n);
        function1(n-1);
    }
}

int main() {
    cout << "**** tail recursion ****\n";
    int x = 17;

    function1(x);
    return 0;
}
