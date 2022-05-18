'''
Given an array nums containing n distinct numbers in the range [0,n], return number in the range that is missing
from the array.

# example 1
input:
nums = [3,0,1]

output:
2

explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3].  2 is the missing number in range since
it does not appear in nums.

# example 2
input:
nums = [0,1]

output:
2

explanation:
n = 2 since there are 2 numbers, so all numbers are in range [0,2].  2 is the missing number in the range since
it does not appear in nums.

# example 3
input:
nums = [9,6,4,2,3,5,7,0,1]

output:
8

explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9].  8 is the missing number in range
since it does not appear in nums.

constraints:
n == nums.length
1 <= n <= 10^4
0 <= nums[i] <= n
All numbers of nums are unique.

best time complexity: O(n)
best space complexity:  O(1)

**** missing number ****


'''
from typing import List

class MissingNumber():
    def start1(self,nums: List[int]) -> int:
        currentSum = sum(nums)
        n = len(nums)
        gaussianSum = (n * (n + 1)) / 2

        return int(gaussianSum - currentSum)

    # time complexity of sort: O(n * log(n)); space complexity: O(n)
    def start2(self,numberArr: List[int]) -> int:
        n = len(numberArr)
        numberArr.sort()

        if (n == 0):
            return "error"

        for i in range(0,n):
            if (i == 0):
                continue

            difference = numberArr[i] - numberArr[i - 1]
            if (difference != 1):
                if (numberArr[i] > numberArr[i - 1]):
                    missingNumber = numberArr[i] - 1
                    return missingNumber
                else:
                    missingNumber = numberArr[i - 1] - 1
                    return missingNumber

print("**** missing number ****")
m = MissingNumber()
arr1 = [3,0,1,2,5]
arr2 = [0,4,8,3,5,2,1,7,6,10]
arr3 = [1,4,3,0,2,7,5]

result1 = m.start1(arr1)
print("array1: {0}\nresult1: {1}".format(arr1,result1))

print("array2: {0}".format(arr2))
result2 = m.start2(arr2)
print("result2: {0}".format(result2))

print("array3: %s" % arr3)
result3 = m.start2(arr3)
print("result3: {0}".format(result3))