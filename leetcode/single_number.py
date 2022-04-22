'''
Given a non-empty array of integers called nums, every element appears twice except for one and find that single
one.  One must implement a solution with linear runtime complexity and use only constant extra space.

# example 1
input:
nums = [2,2,1]

output:
1

# example 2
input:
nums = [4,1,2,1,2]

output:
4

# example 3
input:
nums = [1]

output:
1

constraints:
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for an element which appears once.


**** single number ****

'''
class SingleNumber():
    def begin1(self,nums):
        return 2 * sum(set(nums)) - sum(nums)

    def begin2(self,nums):
        # 2 * sum of distinct number array minus sum of original array
        numArr = []
        totalSum = 0
        numsSum = 0
        # get distinct numbers
        for i in nums:
            if (i not in numArr):
                numArr.append(i)

        for i in numArr:
            totalSum += i

        for i in nums:
            numsSum += i

        missingNumber = (2 * totalSum) - numsSum
        return missingNumber

print("**** single number ****")
s = SingleNumber()
arr1 = [4,1,2,1,2]
arr2 = [3,5,3,5,7,7,8]

result1 = s.begin1(arr1)
print("array1: {0}\nresult1: {1}".format(arr1,result1))
result2 = s.begin2(arr2)
print("array2: {0}\nresult2: {1}".format(arr2,result2))
