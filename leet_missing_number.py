'''
Find missing number in array
best time complexity: O(n)
best space complexity:  O(1)
'''

from typing import List

class MissingNumber:
    def start(self,nums: List[int]) -> int:
        currentSum = sum(nums)
        n = len(nums)
        # gauss formula
        intendedSum = (n * (n + 1)) / 2

        return int(intendedSum - currentSum)

m = MissingNumber()
arr = [3,0,1,2,5]
result = m.start(arr)
print("missing number: ",result)