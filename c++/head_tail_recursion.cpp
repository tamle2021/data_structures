/*
Example of head and tail recursion
*/

#include <stdio.h>
#include <iostream>

using namespace std;

void headFunc(int n) {
    if (n > 0) {
        headFunc(n - 1);
        printf("%d ",n);
    }
}

void tailFunc(int n) {
    if (n > 0) {
        printf("%d ",n);
        tailFunc(n - 1);
    }
}

int main() {
    int x = 5;
    cout << "**** head recursion **** \n";
    headFunc(x);

    cout << "\n\n";
    cout << "**** tail recursion **** \n";
    tailFunc(5);

    return 0;
}

