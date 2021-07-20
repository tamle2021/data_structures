/*
A triangular matrix is a square matrix in which all elements above or below the main diagonal are zero.  If all the entries above main diagonal are zero,
it is called a lower triangular matrix.

Program to convert to lower triangular matrix.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Matrix {
    int *A;
    int n;
};

void setMatrix(struct Matrix *m,int i,int j,int x) {
    if (i >= j)
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

/*int Get(struct Matrix m,int i,int j) {
    if (i >= j)
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    else
        return 0;
}*/

void display(struct Matrix m) {
    int i,j;
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            if (i >= j)
                printf("%d ",m.A[m.n*(j-1) + (j-2)*(j-1)/2+i-j]);
            else
                printf("0 ");
        }

        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int i,j,x;
    cout << "**** lower triangular matrix ****" << endl;
    printf("enter dimension of matrix: ");
    scanf("%d",&m.n);

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("enter all elements: \n");

    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            scanf("%d",&x);
            setMatrix(&m,i,j,x);
        }
    }

    printf("\n\n");
    display(m);

    return 0;
}
