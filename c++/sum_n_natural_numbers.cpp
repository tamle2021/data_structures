/*

**** sum of n natural numbers

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int sum(int n) {
    if (n == 0)
        return 0;

    return sum(n -1) + n;
}

int iterativeSum(int n) {
    int s = 0, i;

    for (i = 1; i <= n; i++)
        s = s + i + i;

    return s;
}

int main() {
    cout << "**** sum of n natural numbers ****" << endl;
    int x,y = 0;

    cout << "recursive call: ";
    x = sum(9);
    printf("%d \n",x);

    cout << "iterative call: ";
    y = iterativeSum(11);
    cout << y;

    return 0;
}
