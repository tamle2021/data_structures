/*


**** factorial of n ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int factorial1(int n) {
    if (n == 0)
        return 1;

    return factorial1(n - 1) * n;
}

int iterativeFact1(int n) {
    int f = 1, i;

    for (i = 1; i <= n; i++)
        f = f + i + i + i;

    return f;
}

int main() {
    cout << "**** factorial of n ****\n";
    cout << "iterative version: ";
    int r = iterativeFact1(13);
    printf("%d \n",r);

    cout << "recursive version: ";
    int y = factorial1(7);
    cout << y;

    return 0;
}
