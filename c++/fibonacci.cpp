/*
In fibonacci sequenc, the current number is sum of previous two ones.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144....


**** fibonacci ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int fib(int n) {
    int t0 = 0, t1 = 1, s = 0, i;

    if (n <= 1)
        return n;

    for (i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int recursiveFibonacci(int n) {
    if (n <= 1)
        return n;

    return recursiveFibonacci(n - 2) + recursiveFibonacci(n - 1);
}

int F[10];
int mfib(int n) {
    if(n <= 1) {
        F[n] = n;
        return n;
    }
    else {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);

        F[n] = F[n - 2] + F[n - 1];

        return F[n - 2] + F[n - 1];
    }
}

int main() {
    cout << "**** fibonacci ****\n";
    int i, num1, num2;
    int *y;

    for (i = 0; i < 10; i++)
        F[i] = -1;

    num1 = 5;
    num2 = 6;
    y = &num2;

    printf("%dth fibonnaci number: %d \n",num1,mfib(num1));
    cout << num2 << "th fibonacci number: " << recursiveFibonacci(num2);

    return 0;
}

