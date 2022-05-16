/*



**** array menu ****

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void displayIt(struct Array arr) {
    int i;
    printf("elements: ");

    for (i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
}

void appendIt(struct Array *arr,int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void insertIt(struct Array *arr,int index,int x) {
    int i;

    if (index >= 0 && index <= arr->length) {
        // shifting elements to right
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int deleteIt(struct Array *arr,int index) {
    int x = 0;
    int i;

    if (index >= 0 && index<arr->length) {
        x = arr->A[index];
        // shifting elements to the left
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];

        arr->length--;
        return x;
    }

    return 0;
}

void swapIt(int *x,int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr,int key) {
    int i;

    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            swapIt(&arr->A[i],&arr->A[0]);
            return i;
        }
    }

    return -1;
}

int binarySearch(struct Array arr,int key) {
    int l,mid,h;
    l = 0;
    h = arr.length - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        // search upper side
        else
            l = mid + 1;
    }

    return -1;
}

// recursive binary search
int recBinarySearch(int a[],int l,int h,int key) {
    int mid;

    if (l <= h) {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return recBinarySearch(a,l,mid - 1,key);
        else
            return recBinarySearch(a,mid + 1,h,key);
    }

    return -1;
}

int getIt(struct Array arr,int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];

    return -1;
}

void setIt(struct Array *arr,int index,int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int maxIt(struct Array arr) {
    int max1 = arr.A[0];
    int i;

    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] > max1)
            max1 = arr.A[i];
    }

    return max1;
}

int minIt(struct Array arr) {
    int min1 = arr.A[0];
    int i;

    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] < min1)
            min1 = arr.A[i];
    }

    return min1;
}

int sumIt(struct Array arr) {
    int sum1 = 0;
    int i;

    for (i = 0; i < arr.length; i++)
        sum1 += arr.A[i];

    return sum1;
}

float average1(struct Array arr) {
    return (float)sumIt(arr) / arr.length;
}

void reverseIt(struct Array *arr) {
    int *B;
    int i,j;
    B = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length - 1,j = 0; i >= 0; i--,j++)
        B[j] = arr->A[i];
    // copy it back to original array
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void reverse2(struct Array *arr) {
    int i,j;

    for (i = 0,j = arr->length - 1; i < j; i++,j--) {
        swapIt(&arr->A[i],&arr->A[j]);
    }
}

void insertSort(struct Array *arr,int x) {
    int i = arr->length - 1;

    if (arr->length == arr->size)
        return;

    // shifting elements to right
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) {
    int i;

    for (i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }

    return 1;
}

void rearrange(struct Array *arr) {
    int i,j;
    i = 0;
    j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;

        if (i < j)
            swapIt(&arr->A[i],&arr->A[j]);
    }
}

// similar to operation in merge sort
struct Array* mergeIt(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct Array* unionIt(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    // clean-up operations
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array* intersection1(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* difference1(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else {
            i++;
            j++;
        }
    }

    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main() {
    cout << "**** array menu ****\n";
    struct Array arr1;
    int ch;
    int x,index;

    printf("enter size of array: ");
    scanf("%d",&arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do {
        printf("\n\nmenu => \n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. search\n");
        printf("4. sum\n");
        printf("5. display\n");
        printf("6. exit\n");
        printf("enter you choice: ");

        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("enter element and index: ");
                scanf("%d%d",&x,&index);
                insertIt(&arr1,index,x);
                break;
            case 2:
                printf("enter index: ");
                scanf("%d",&index);
                x = deleteIt(&arr1,index);
                printf("deleted element: %d\n",x);
                break;
            case 3:
                printf("enter element to search: ");
                scanf("%d",&x);
                index = linearSearch(&arr1,x);
                printf("index: %d",index);
                break;
            case 4:
                printf("sum: %d\n",sumIt(arr1));
                break;
            case 5:
                displayIt(arr1);
        }
    } while (ch < 6);

    return 0;
}

