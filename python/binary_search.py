'''
Binary search is a searching algorithm which is used to search a particular element's position in a given sorted
array. In this algorithm the targeted element is compared with middle element.  If both elements are equal, then
position of middle element is returned and target is found.  If both elements are unequal, then comparison is made
with target and middle element and we discard lower or upper half depending on outcome of comparison.  The search
continues with new middle elements until the target is found or search is exhausted.

time complexity: O(log(n))
space complexity: O(1)


**** binary search ****

'''

def binarySearch(arr,target):
    left = 0
    right = len(arr) - 1

    while (left <= right):
        mid = (left + right) // 2

        # check if value present at mid
        if (arr[mid] == target):
            return mid
        # if x is greater, ignore left half
        elif (arr[mid] < target):
            left = mid + 1
        # if x is smaller, ignore right half
        else:
            right = mid - 1

    # if we reach here, then element is not present
    return -1

print("**** binary search ****")
arr = [-45,199,21,25,-126,1,66,2,6,44,3,23,-61,4,5,87]
target1 = 6
target2 = -8

print("array: %s" % arr)
result1 = binarySearch(arr,target1)
print("target1: {0}\nresult1: {1}".format(target1,result1))
result2 = binarySearch(arr,target2)
print("target2: {0}\nresult2: {1}".format(target2,result2))
