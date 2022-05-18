'''
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
Robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). Robot can only move either down or
right at any point in time.  Given two integers m and n, return the number of possible unique paths that
robot can take to reach bottom-right corner.  The test cases are generated so that answer will be less
than or equal to 2 * 10^9.

# example 1
input:
m = 3, n = 7

output:
28

# example 2
input:
m = 3, n = 2

output:
3

explanation:
From top-left corner, there are a total of 3 ways to reach bottom-right corner.
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

constraints:
1 <= m, n <= 100


**** unique paths ****
*** dynamic programming ***


'''
class UniquePaths():
    def start(self,m: int,n: int) -> int:
        # initialize m x n matrix
        dp = [[0 for x in range(m)] for y in range(n)]
        for i in range(m):
            dp[0][i] = 1

        for i in range(n):
            dp[i][0] = 1

        for i in range(1,n):
            for j in range(1,m):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[-1][-1]

print("**** unique paths ****")
u = UniquePaths()
m1 = 3
n1 = 2
m2 = 4
n2 = 3

result1 = u.start(m1,n1)
print("result1: {0}".format(result1))
result2 = u.start(m2,n2)
print("result2: {0}".format(result2))