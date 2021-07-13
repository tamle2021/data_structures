'''
Given an integer array nums of unique elements, return all possible subsets or power set.
It must not contain duplicate subsets and can be in any order.

example 1:
input: nums = [1,2,3]
output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

example 2:
input: nums = [0]
output: [[],[0]]

constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

'''

from typing import List

class Subsets:
    def recurse(self,nums,ans,cur,index):
        if (index > len(nums)):
            return
        ans.append(cur[:])

        for i in range(index,len(nums)):
            if (nums[i] not in cur):
                cur.append(nums[i])
                self.recurse(nums,ans,cur,i)
                cur.pop()
        return

    def getSubsets(self,nums: List[int]) -> List[List[int]]:
        ans = []
        cur = []
        self.recurse(nums,ans,cur,0)
        return ans

s = Subsets()
result = s.getSubsets([1,2,3])
print(result)