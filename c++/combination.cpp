/*
In how many ways can we pick r numbers from n given ordering does not matter?


**** combination ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

// calculate factorial of number
int factorial(int n) {
    if (n == 0)
        return 1;

    return factorial(n - 1) * n;
}

int nCr(int n,int r) {
    int num,den;
    num = factorial(n);
    den = factorial(r) * factorial(n - r);

    return num / den;
}

// another combination formula
int NCR(int n,int r) {
    if (n == r || r == 0)
        return 1;

    return NCR(n - 1,r - 1) + NCR(n - 1,r);
}

int main() {
    cout << "**** combination ****\n";
    int n1 = 5, r1 = 3;
    int n2 = 12, r2 = 4;

    printf("%d choose %d: %d\n",n1,r1,NCR(n1,r1));
    cout << n2 << " choose " << r2 << ": " << nCr(n2,r2);

    return 0;
}



