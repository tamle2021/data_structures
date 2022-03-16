/*



**** power recursion ****

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int powerOne(int m,int n) {
    if (n == 0)
        return 1;

    return powerOne(m,n - 1) * m;
}

int powerTwo(int m,int n) {
    if (n == 0)
        return 1;
    if ((n % 2) == 0)
        return powerTwo(m * m,n / 2);

    return m * powerTwo(m * m,(n - 1) / 2);

}

int main () {
    cout << "**** power recursion ****\n";
    int n1 = 3;
    int e1 = 11;
    int n2 = 4;
    int e2 = 3;
    int result1 = powerOne(n1,e1);
    int result2 = powerTwo(n2,e2);

    cout << "power1:  " << n1 << " raised to the " << e1 << "\nresult1: " << result1 << endl;
    cout << "power2:  " << n2 << " raised to the " << e2 << "\nresult2: " << result2 << endl;

    return 0;
}
