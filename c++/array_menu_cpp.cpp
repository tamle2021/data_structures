/*



**** array menu c++ implementation ****

*/
#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

    void swapIt(int *x,int *y);

public:
    // constructors
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() {
        delete []A;
    }

    void displayIt();
    void appendIt(int x);
    void insertIt(int index,int x);
    int deleteIt(int index);
    int linearSearch(int key);
    int binarySearch(int key);
    int getIt(int index);
    void setIt(int index,int x);
    int max1();
    int min1();
    int sum1();
    float averageIt();
    void reverse1();
    void reverse2();
    void insertSort(int x);
    int isSorted();
    void rearrange();
    Array* merge1(Array arr2);
    Array* union1(Array arr2);
    Array* difference(Array arr2);
    Array* intersection1(Array arr2);
};

void Array::displayIt() {
    int i;

    cout<<"elements: ";
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
}

void Array::appendIt(int x) {
    if (length < size)
        A[length++] = x;
}

void Array::insertIt(int index,int x) {
    int i;

    if (index >= 0 && index <= length) {
        // shifting elements to right
        for (i = length; i > index; i--)
            A[i] = A[i - 1];

        A[index] = x;
        length++;
    }
}

int Array::deleteIt(int index) {
    int x = 0;
    int i;

    if (index >= 0 && index<length) {
        x = A[index];
        // shifting elements to left
        // deleted element gets overwritten at first iteration
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];

        length--;
        return x;
    }

    return 0;
}

void Array::swapIt(int *x,int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::linearSearch(int key) {
    int i;

    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            swapIt(&A[i],&A[0]);
            return i;
        }
    }

    return -1;
}

int Array::binarySearch(int key) {
    int l,mid,h;
    l = 0;
    h = length - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        // search upper side
        else
            l = mid + 1;
    }

    return -1;
}

int Array::getIt(int index) {
    if (index >= 0 && index < length)
        return A[index];

    return -1;
}

void Array::setIt(int index,int x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::max1() {
    int max2 = A[0];
    int i;

    for (i = 1; i < length; i++) {
        if (A[i] > max2)
            max2 = A[i];
    }

    return max2;
}

int Array::min1() {
    int min2 = A[0];
    int i;

    for (i = 1; i < length; i++) {
        if (A[i] < min2)
            min2 = A[i];
    }

    return min2;
}

int Array::sum1() {
    int sum = 0;
    int i;

    for (i = 0; i < length; i++)
        sum += A[i];

    return sum;
}

float Array::averageIt() {
    return (float)sum1() / length;
}

void Array::reverse1() {
    int *B;
    int i,j;
    B = (int *)malloc(length * sizeof(int));

    for (i = length - 1,j = 0; i >= 0; i--,j++)
        B[j] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::reverse2() {
    int i,j;

    for (i = 0,j = length - 1; i < j; i++,j--) {
        swapIt(&A[i],&A[j]);
    }
}

void Array::insertSort(int x) {
    int i = length - 1;

    if (length == size)
        return;

    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }

    A[i + 1] = x;
    length++;
}

int Array::isSorted() {
    int i;

    for (i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1])
            return 0;
    }

    return -1;
}

void Array::rearrange() {
    int i,j;
    i = 0;
    j = length - 1;

    while (i < j) {
        // swapping positive elements with negative starting at opposite ends
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;

        if (i < j)
            swapIt(&A[i],&A[j]);
    }
}

// merge elements from two arrays into single array
Array* Array::merge1(Array arr2) {
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for(; i < length; i++)
        arr3->A[k++] = A[i];
    for(; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = length + arr2.length;
    return arr3;
}

Array* Array::union1(Array arr2) {
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for(; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

Array* Array::intersection1(Array arr2) {
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if (A[i] == arr2.A[j]) {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    return arr3;
}

Array* Array::difference(Array arr2) {
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = k;
    return arr3;
}

int main() {
    cout <<  "**** array menu c++ implementation ****\n";
    Array *arr1;
    int ch,sz;
    int x,index;

    cout << "enter size of array: ";
    scanf("%d",&sz);
    arr1 = new Array(sz);

    do {
        cout<<"\n\nmenu\n";
        cout<<"1. insert\n";
        cout<<"2. delete\n";
        cout<<"3. search\n";
        cout<<"4. sum\n";
        cout << "5. average\n";
        cout<<"6. display\n";
        cout<<"7. exit\n";
        cout<<"enter choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout<<"enter element and index: ";
                cin >> x >> index;
                arr1->insertIt(index,x);
                break;
            case 2:
                cout << "enter index: ";
                cin >> index;
                x = arr1->deleteIt(index);
                cout<<"deleted element: " << x;
                break;
            case 3:
                cout<< "enter search element: ";
                cin >> x;
                index = arr1->linearSearch(x);
                cout << "index: " << index;
                break;
            case 4:
                cout << "sum: " << arr1->sum1();
                break;
            case 5:
                cout << "average: " << arr1->averageIt();
                break;
            case 6:
                arr1->displayIt();
        }
    } while (ch <= 6);

    return 0;
}


