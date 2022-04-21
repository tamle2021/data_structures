'''
Given an array of distinct integers candidates and an integer target, return a list of all unique combinations
of candidates where the chosen numbers sum to target.  One may return combinations in any order.  The same number
may be chosen from candidates an unlimited number of times. Two combinations are unique if frequency of at least
one of the chosen numbers is different.  It is guaranteed that number of unique combinations that sum up to target
is less than 150 combinations for the given input.

# example 1
input:
candidates = [2,3,6,7], target = 7

output:
[[2,2,3],[7]]

explanation:
2 and 3 are candidates and 2 + 2 + 3 = 7.  Note that 2 can be used multiple times.
7 is a candidate and 7 = 7.
These are the only two combinations.

# example 2
input:
candidates = [2,3,5], target = 8

output:
[[2,2,2,2],[2,3,3],[3,5]]

# example 3
input:
candidates = [2], target = 1

output:
[]

constraints:
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500


**** combination sum I ****

'''
class CombinationSumI():
    def begin(self,candidates,target):
        result = []
        candidates.sort()
        # check for no candidates
        if (not candidates):
            return []

        self.computeSum(candidates,0,[],target,result)
        return result

    def computeSum(self,candidates,start,sumArr,target,result):
        if (target == 0):
            result.append(sumArr)
            return

        for i in range(start,len(candidates)):
            # stop the current search if candidate is larger
            if (candidates[i] > target):
                return

            self.computeSum(candidates,i,sumArr + [candidates[i]],target - candidates[i],result)

print("**** combination sum I ****")
c = CombinationSumI()
candidates1 = [2,3,6,7]
target1 = 7
candidates2 = []
target2 = 3
candidates3 = [12,4,9,11,2]
target3 = 23
candidates4 = [3]
target4 = 1

result1 = c.begin(candidates1,target1)
print(f"candidates1: {candidates1}\ntarget1: {target1}\nresult1: {result1}")
result2 = c.begin(candidates2,target2)
print(f"candidates2: {candidates2}\ntarget2: {target2}\nresult2: {result2}")
result3 = c.begin(candidates3,target3)
print(f"candidates3: {candidates3}\ntarget3: {target3}\nresult3: {result3}")
result4 = c.begin(candidates4,target4)
print(f"candidates4: {candidates4}\ntarget4: {target4}\nresult4: {result4}")


