/*
Recursion using static variable
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int fun(int n) {
    static int x = 0;
    if (n > 0) {
        x++;
        return fun(n-1) + x;
    }

    return 0;
}

int main() {
    int r;
    cout << "**** recursion using static variable *****" << endl;
    r = fun(6);
    printf("%d\n",r);

    r = fun(6);
    printf("%d\n",r);

    r = fun(6);
    printf("%d\n",r);

    return 0;
}
