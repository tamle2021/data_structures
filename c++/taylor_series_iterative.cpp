/*
Taylor Series is an expansion of some function into an infinite sum of terms, where each term has a larger exponent like x, x2, x3,
etc.


**** taylor series iterative ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

double func1(int e,int x) {
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i  = 1; i <= x; i++) {
        num *= e;
        den *= i;
        s += num / den;
    }

    return s;
}

int main() {
    cout << "**** taylor series iterative ****\n";
    int e = 2;
    int x = 8;

    cout << e << " to the " << x << " = ";
    printf("%lf \n",func1(e,x));

    return 0;
}
