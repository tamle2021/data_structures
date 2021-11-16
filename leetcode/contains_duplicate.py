'''
Given an integer array, return true if any value appears at least twice in array and return false if every element
is distinct or no duplicate.

example:
input: nums = [1,2,3,1]
output: true

**** contains duplicate ****

'''

from collections import defaultdict
from typing import List

def containsDuplicate(nums: List[int]) -> bool:
    m = defaultdict(int)

    for num in nums:
        if m[num]:
            return True
        m[num] += 1
    return False

print("**** contains duplicate ****")
arr1 = [4,0,1,2,6,99,87,4]
arr2 = [25,3,-6,9,11,0,112,343]
result1 = containsDuplicate(arr1)
result2 = containsDuplicate(arr2)

if (result1):
    print("array %s contains duplicate" % arr1)
else:
    print("array {0} contains no duplicate".format(arr1))

if (result2):
    print("array %s contains duplicate" % arr2)
else:
    print("array {0} contains no duplicate".format(arr2))