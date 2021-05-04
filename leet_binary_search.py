def binarySearch(arr,target):
    left = 0
    right = len(arr)-1
    while (left <= right):
        mid = (left+right)//2

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

arr = [-45,199,25,-126,1,66,2,6,44,3,23,4,5,87]
target = 6

result = binarySearch(arr,target)

if (result != -1):
    print("element is present at index: %d" % result)
else:
    print("element is not present in array...")