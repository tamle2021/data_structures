/*
Nested recursion is where the argument passed to the function is itself.


**** nested recursion ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int func1(int n) {
    if(n >= 144)
        return n - 9;

    return func1(func1(n + 9));
}

int main() {
    cout << "**** nested recursion ****" << endl;
    int r;

    r = func1(100);
    printf("%d\n",r);

    return 0;
}
