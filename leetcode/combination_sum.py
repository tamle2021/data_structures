'''
Given an array of distinct integer called candidates and a target integer called target, return a list
of all unique combinations of candidates where the chosen numbers sum to target.  One may return
combinations in any order.  The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150
combinations for the given input.

input: candidates = [2,3,6,7], target = 7
output: [[2,2,3],[7]]
explanation: 2 and 3 are candidates and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate and 7 = 7 and these are the only two combinations.

'''
from typing import List

class CombinationSum:
    def recurse(self,candidates,result,cur,target,index,sum):
        if (sum == target):
            result.append(cur[:])
        elif (sum < target):
            n = len(candidates)
            for i in range(index,n):
                cur.append(candidates[i])
                self.recurse(candidates,result,cur,target,i,sum + candidates[i])
                cur.pop()
        return

    def startProcess(self,candidates: List[int],target: int) -> List[List[int]]:
        result = []
        cur = []
        self.recurse(candidates,result,cur,target,0,0)

        return result

c = CombinationSum()
candidates = [1,4,8,3]
target = 11
result = c.startProcess(candidates,target)
print("result: {i}".format(i=result))
print("count:",len(result))