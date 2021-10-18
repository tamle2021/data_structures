'''
Binary search is a searching algorithm which is used to search a particular element's position in a given sorted
array/vector. In this algorithm the targeted element is compared with middle element.
If both elements are equal then position of middle element is returned and hence targeted element is found.
If both elements are unequal, then a comparison is made with target and middle elements and
we discard the lower or upper half depending on outcome of comparison.  The search continues with new middle elements
until the target is found.

space complexity: O(1)
'''

def binarySearch(arr,target):
    left = 0
    right = len(arr) - 1
    while (left <= right):
        mid = (left + right) // 2

        # check if x is present at mid
        if (arr[mid] == target):
            return mid
        # if x is greater, ignore left half
        elif (arr[mid] < target):
            left = mid + 1
        # if x is smaller, ignore right half
        else:
            right = mid - 1

    # if we reach here, then the element was not present
    return -1

arr = [-45,199,21,25,-126,1,66,2,6,44,3,23,-61,4,5,87]
target = 6

result = binarySearch(arr,target)

if (result != -1):
    print("element is present at index: %d" % result)
else:
    print("element is not present in array...")