'''
Given an array nums of size n, return majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.  One may assume that the majority element always
exists in the array.

example:
input: nums = [3,2,3]
output: 3

constraints:
n == nums.length
1 <= n <= 5 * 10^4
-2^31 <= nums[i] <= 2^31 - 1


time complexity: O(n)
space complexity: O(n)

**** majority element ****

'''
from typing import List

def majorityElement(array: List[int]) -> int:
    global majorityFlag
    majorityFlag = False
    m = {}
    for num in array:
        m[num] = m.get(num,0) + 1
    for num in array:
        if (m[num] > len(array) // 2):
            majorityFlag = True
            return num

print("**** majority element ****")

arr1 = [4,2,1,0,0,0]
result1 = majorityElement(arr1)
print("array 1: {0}".format(arr1))
if (majorityFlag):
    print("majority: %s\n" %  result)
else:
    print("no majority....\n")

arr2 = [3,4,-4,0,7,7,7,7,7]
result2 = majorityElement(arr2)
print("array 2: {0}".format(arr2))
if (majorityFlag):
    print("majority: %s" %  result2)
else:
    print("no majority....")

