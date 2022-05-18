'''
One is climbing a staircase. It takes n steps to reach the top.  It can only be 1 or 2 steps at a time.  In how many
distinct ways can a person climb to top?

# example 1
input:
n = 2

output:
2

explanation:
There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

# example 2
input:
n = 3

output:
3

explanation:
There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


constraints:
1 <= n <= 45

**** climbing stairs ****
*** dynamic programming ***

'''

class ClimbingStairs():
    def start(self,n: int) -> int:
        if (n == 1):
            return 1

        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2

        for i in range(3,n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]


print("**** climbing stairs ****")
c = ClimbingStairs()
input1 = 4
input2 = 7

result1 = c.start(input1)
print(f"input1: {input1}\nresult1: {result1}")
result2 = c.start(input2)
print(f"input2: {input2}\nresult2: {result2}")


