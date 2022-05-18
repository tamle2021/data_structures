'''
Given an array of integers and integer target, return indices of two numbers such that they add up to target.
time and space complexity: O(n)

example:
input: nums = [2,7,11,15], target = 9
output: [0,1]
Because nums[0] + nums[1] is equal to 9, we return [0,1].

**** two sum ****
'''
from typing import List
foundFlag = False

def twoSum(arr: List[int],target: int) -> List[int]:
    global matchFlag
    matchFlag = False
    m = {}
    n = len(arr)
    for i in range(0,n):
        goal = target - arr[i]
        if (goal in m):
            matchFlag = True
            return [m[goal],i]
        m[arr[i]] = i

print("**** two sum ****")
arr = [2,5,4,-2,0,24,51,1,99,188,254,11,-13,7]
target1 = 9
target2 = -13
target3 = 105

result1 = twoSum(arr,target1)
if (matchFlag == True):
    print("indexes of target %s: %s" % (target1,result1))
else:
    print("no match for target %s" % target1)

result2 = twoSum(arr,target2)
if (matchFlag == True):
    print("indexes of target %s: %s" % (target2,result2))
else:
    print("no match for target %s" % target2)

result3 = twoSum(arr,target3)
if (matchFlag == True):
    print("indexes of target %s: %s" % (target3,result3))
else:
    print("no match for target %s" % target3)




