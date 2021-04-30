"""
Heap sort happens in two phases. In the first phase, the array is transformed into a heap.
A heap is a binary tree where each node is greater than each of its children amd the tree is
perfectly balanced.  All leaves are in the leftmost position available.  In phase two, the heap
is continuously reduced to a sorted array.  While the heap is not empty, remove the top of the
head into an array and fix the heap.  The move down method checks and verifies that the structure is a heap.

A heap is based on an array just as a hashmap is based on an array. For a heap, the children of an element n
are at index 2n+1 for the left child and 2n+2 for the right child.

The move down function checks that an element is greater than its children. If not, the values of element
and child are swapped. The function continues to check and swap until the element is at a position where 
it is greater than its children.

Time Complexity of Solution:
best => O(nlog(n)); 
average => O(nlog(n)) 
worst => O(nlog(n)).
"""

count = 0

def heapsort(aList):
    global count
    # convert to heap
    length = len(aList) - 1
    leastParent = length / 2
    for i in range (int(leastParent),-1,-1):
        moveDown(aList,i,length)

    # flatten heap into sorted array
    for i in range (length,0,-1):
        if (aList[0] > aList[i]):
            swap(aList,0,i)
            moveDown(aList,0,i - 1)

def moveDown(aList,first,last):
    largest = 2 * first + 1
    while (largest <= last):
        # right child exists and is larger than left child
        if (largest < last) and (aList[largest] < aList[largest + 1]):
            largest += 1

        # right child is larger than parent
        if (aList[largest] > aList[first]):
            swap(aList,largest,first)
            # move down to largest child
            first = largest;
            largest = 2 * first + 1
        else:
            return

def swap(A,x,y):
    global count
    count = count + 1
    tmp = A[x]
    A[x] = A[y]
    A[y] = tmp

if (__name__ == "__main__"):
    aList = [2,3,92,4,11,0,22,211,1234,19,777,55]
    print("before sort: %s" % aList)
    heapsort(aList)
    print("after sort: %s" % aList)
    print("count swap: %s" % count)
