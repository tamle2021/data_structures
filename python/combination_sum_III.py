'''
Find all valid combinations of k numbers that sum up to n such that only numbers 1 through 9 are used and each
number is used at most once.  Return a list of all possible valid combinations. The list must not contain the same
combination twice and the combinations may be returned in any order.

# example 1
input:
k = 3, n = 7

output:
[[1,2,4]]

explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

# example 2
input:
k = 3, n = 9

output:
[[1,2,6],[1,3,5],[2,3,4]]

explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

# example 3
input:
k = 4, n = 1

output:
[]

explanation:
There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1 + 2 + 3 + 4 = 10 and since 10 > 1,
there are no valid combination.

constraints:
2 <= k <= 9
1 <= n <= 60

**** combination sum III ****


'''
from typing import List

class CombinationSumIII():
    def start(self,k: int,n: int) -> List[List[int]]:
        self.result = []
        self.dfs(1,k,n,[])
        return self.result

    # depth-first search?
    def dfs(self,cur,k,target,tempArr):
        if (k == 0):
            if (target == 0):
                self.result.append(tempArr[:])
            return

        for i in range(cur,10):
            if (target < i):
                return

            tempArr.append(i)
            # recursive call in which numbers used get decremented and current target gets updated
            self.dfs(i + 1,k - 1,target - i,tempArr)
            tempArr.pop()

print("**** combination sum III ****")
c = CombinationSumIII()
k1 = 3
n1 = 7
k2 = 4
n2 = 10

result1 = c.start(k1,n1)
print("(k1,n1): %s,%s\nresult1: %s" % (k1,n1,result1))
result2 = c.start(k2,n2)
print("(k2,n2): %s,%s\nresult2: %s" % (k2,n2,result2))
