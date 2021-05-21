/*
A diagonal matrix is a type of square matrix in which all off-diagonal elements are zero.
Implementation using class.

enter dimensions: 2
enter all elements: 2 0 0 2
2 0
0 2
*/
#include <iostream>

using namespace std;

class Diagonal {
private:
    int *A;
    int n;

public:
    Diagonal() {
        n = 2;
        A = new int[2];
    }

    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }

    ~Diagonal() {
        delete []A;
    }

    void setMatrix(int i,int j,int x);
    int get(int i,int j);
    void display();

    int getDimension() {
        return n;
    }
};

void Diagonal::setMatrix(int i,int j,int x) {
    if (i == j)
        A[i-1] = x;
}

int Diagonal::get(int i,int j) {
    if (i == j)
        return A[i-1];

    return 0;
}

void Diagonal::display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << A[i-1] << " ";
            else
                cout << "0 ";
        }

        cout << endl;
    }
}

int main() {
    int d;
    cout << "enter dimensions: ";
    cin >> d;

    Diagonal dm(d);
    int x;
    cout << "enter all elements: ";
    for (int i = 1; i <= d; i++) {
        for (int j = 1;j <= d; j++) {
            cin >> x;
            dm.setMatrix(i,j,x);
        }
    }

    dm.display();
    return 0;
}
