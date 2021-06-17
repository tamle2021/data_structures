/*
Recursion using global variable
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int x = 0;

int fun(int n) {
    if (n > 0) {
        x++;
        return fun(n-1)+x;
    }

    return 0;
}

int main() {
    int r;
    cout << "**** recursion using global variable ****\n";
    r = fun(7);
    printf("%d\n",r);

    r = fun(7);
    printf("%d\n",r);

    return 0;
}
