/*
Bubble sort, also referred to as comparison sort, is a sorting algorithm that repeatedly goes through list and compares
and swaps adjacent elements.

time complexity: O(n^2)

**** bubble sort ****
*/

#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

void swap(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
 }
void bubble(int A[],int n) {
    int i,j,flag = 0;
    for (i = 0; i < n - 1; i++) {
        flag=0;
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

int main() {
    cout << "**** bubble sort ****\n";
    int A[] = {111,12,1,74,0,9,-21,17,51,18,94,41},n = 12, i;

    cout  << "before sort: \n";
    for (i = 0; i < 11; i++)
        cout << A[i] << " ";
    bubble(A,n);
    cout << "\nafter sort: \n";
    for (i = 0; i < 11; i++)
        printf("%d ",A[i]);

    printf("\n");
    return 0;
}
