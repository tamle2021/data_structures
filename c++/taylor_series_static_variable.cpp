/*


**** taylor series using static variable ****
*/
#include <stdio.h>
#include <iostream>

using namespace std;

double e(int x,int n) {
    static double p=1,f=1;
    double r;

    if (n == 0)
        return 1;

    r = e(x,n - 1);
    p = p * x;
    f = f * n;

    return r + p / f;
}

int main() {
    cout  << "**** taylor series using static variable ****\n";
    printf("%lf \n",e(3,17));

    return 0;
}


