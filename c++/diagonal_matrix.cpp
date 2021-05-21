/*
A square matrix in which every element except the principal diagonal elements is zero is called a
diagonal matrix. A square matrix D = [dij]n x n will be called a diagonal matrix if dij = 0, whenever i is not
equal to j. There are many types of matrices like the identity matrix.
*/
#include <iostream>

using namespace std;

struct Matrix {
    int A[10];
    int n;
};

void setMatrix(struct Matrix *m,int i,int j,int x) {
    if (i == j)
        m->A[i-1] = x;
}

int get(struct Matrix m,int i,int j) {
    if (i == j)
        return m.A[i-1];
    else
        return 0;
}

void display(struct Matrix m) {
    int i,j;

    for(i = 0; i < m.n; i++) {
        for(j = 0; j < m.n; j++) {
            if (i == j)
                printf("%d ",m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    // 5 x 5 matrix
    m.n = 5;

    setMatrix(&m,1,1,5);
    setMatrix(&m,2,2,8);
    setMatrix(&m,3,3,9);
    setMatrix(&m,4,4,1);
    setMatrix(&m,5,5,7);
    cout << "diagonal matrix: \n" << endl;
    printf("%d \n",get(m,2,2));
    printf("%d \n",get(m,3,3));
    display(m);

    return 0;
}
