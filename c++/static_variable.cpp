/*
When a variable is declared as static, space for it gets allocated for lifetime of program. Even if the function is called multiple
times, space for static variable is allocated only once and value of variable in previous call gets carried through next
function call.

**** static variable ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int func1(int n) {
    static int x = 0;
    if (n > 0) {
        x = x + 3;
        return func1(n - 1) + x;
    }

    return 0;
}

int main() {
    cout << "**** static variable ****\n";
    int r;
    cout << "first call: ";
    r = func1(11);
    printf("%d\n",r);

    cout << "second call: ";
    r = func1(11);
    printf("%d\n",r);

    cout << "third call: ";
    r = func1(11);
    printf("%d\n",r);

    return 0;
}
