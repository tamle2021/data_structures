'''
One is a professional robber planning to rob houses along a street. Each house has a certain amount of money
stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount
one can rob tonight without alerting authorities.

# example 1
input:
nums = [1,2,3,1]

output:
4

explanation:
Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount one can rob is 1 + 3 = 4.

# example 2
input:
nums = [2,7,9,3,1]

output:
12

explanation:
Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400

**** house robber ****
*** dynamic programming ***


'''
from typing import List

class HouseRobber():
    def begin(self,nums: List[int]) -> int:
        n = len(nums)

        if (n == 0):
            return 0

        dp = [0] * n
        dp[0] = nums[0]

        for i in range(1,n):
            if (i == 1):
                dp[i] = max(nums[0],nums[1])
            else:
                dp[i] = max(dp[i - 1],dp[i - 2] + nums[i])

        return dp[-1]

print("**** house robber ****")
h = HouseRobber()
moneyArray1 = [1,2,3,1]
moneyArray2 = [5,1,4,2,7,34]

result1 = h.begin(moneyArray1)
print(f"money array1: {moneyArray1}\nresult1: {result1}")

result2 = h.begin(moneyArray2)
print(f"money array2: {moneyArray2}\nresult2: {result2}")

