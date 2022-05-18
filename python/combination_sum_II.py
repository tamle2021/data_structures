'''
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in
candidates where the candidate numbers sum to target.  Each number in candidates may only be used once in
combination.  Note: The solution set must not contain duplicate combinations.

# example 1
input:
candidates = [10,1,2,7,6,1,5], target = 8

output:
[[1,1,6],[1,2,5],[1,7],[2,6]]

# example 2
input:
candidates = [2,5,2,1,2], target = 5

output:
[[1,2,2],[5]]

constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30


**** combination sum II ****


'''
class CombinationSumII():
    def begin1(self,candidates,target):
        candidates.sort()
        result = []
        # use recursion to find target
        self.combineSum2(candidates,0,[],result,target)
        return result

    def combineSum2(self,numArr,start,sumArr,result,target):
        # base case and if the sum of the path satisfies the target
        if (target == 0):
            result.append(sumArr)
            return

        for i in range(start,len(numArr)):
            # overcounting and we ignore the duplicates after first element
            if (i > start and numArr[i] == numArr[i - 1]):
                continue

            if (numArr[i] > target):
                break

            # print("sum array + [nums[i]]",sumArr + [nums[i]])
            # 'i + 1' because one element can be used once
            self.combineSum2(numArr,i + 1,sumArr + [numArr[i]],result,target - numArr[i])

print("**** combination sum II ****")
c = CombinationSumII()
candidates1 = [10,1,2,7,6,1,5]
candidates2 = [4,6,11,23,3]
target1 = 7
target2 = 9

result1 = c.begin1(candidates1,target1)
print("candidates1: %s\ntarget1: %s\nresult1: %s" % (candidates1,target1,result1))
result2 = c.begin1(candidates2,target2)
print("candidates2: %s\ntarget2: %s\nresult2: %s" % (candidates2,target2,result2))
