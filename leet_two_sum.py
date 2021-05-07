'''
Return the indexes of two elements whose sum equals target
Time and space complexity: O(n)
'''
from typing import List
foundFlag = False

def twoSum(arr: List[int],target: int) -> List[int]:
    global foundFlag
    m = {}
    n = len(arr)
    for i in range(0,n):
        goal = target - arr[i]
        if (goal in m):
            foundFlag = True
            return [m[goal],i]
        m[arr[i]] = i

arr = [2,5,4,-2,0,1,99,188,254,11,-13,7]
target = 9
indexes = twoSum(arr,target)

if (foundFlag == True):
    print("indexes: %s" % indexes)
else:
    print("not found...")

