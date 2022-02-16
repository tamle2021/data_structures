/*
In indirect recursion, we have the functions calling each other in a mutual fashion.


**** indirect recursion ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

void funcB(int n);

void funcA(int n) {
    if (n > 0) {
        printf("%d ",n);
        funcB(n - 1);
    }
}

void funcB(int n) {
    if (n > 1) {
        printf("%d ",n);
        funcA(n / 2);
    }
}

int main() {
    cout << "**** indirect recursion ****\n";
    funcA(27);

    return 0;
}
