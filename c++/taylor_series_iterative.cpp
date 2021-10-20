/*
The taylor series formula is the representation of any function as an infinite sum of terms.   These terms are calculated from
the values of the function’s derivatives at a single point. This concept is formulated by Scottish mathematician
James Gregory, but formally introduced by English mathematician Brook Taylor in 1715.

**** taylor series iterative implementation ****
*/
#include <stdio.h>
#include <iostream>

using namespace std;

double e(int x,int n) {
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }

    return s;
}

int main() {
    cout << "**** taylor series iterative implementation ****\n";
    printf("%lf \n",e(3,11));
    return 0;
}
