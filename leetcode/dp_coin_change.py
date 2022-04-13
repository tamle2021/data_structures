'''
One is given an integer array coins representing coins of different denominations and an integer amount representing
a total amount of money.  Return the fewest number of coins that is needed to make up that amount.  If that amount of
money cannot be made up by any combination of the coins, return -1.  One may assume there is an infinite
number of each kind of coin.

# example 1
input:
coins = [1,2,5], amount = 11

output:
3

explanation:
11 = 5 + 5 + 1

# example 2
input:
coins = [2], amount = 3

output:
-1

# example 3
input:
coins = [1], amount = 0

output:
0

constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4


**** coin change ****
*** dynamic programming ***

'''
from typing import List

class CoinChange():
    def begin(self,coins: List[int],amount: int) -> int:
        # edge cases
        if (amount <= 0):
            return 0

        if (min(coins) > amount):
            return -1

        INT_MAX = 1 << 32
        # create array of size amount plus 1 elements
        dp = [INT_MAX] * (amount + 1)

        dp[0] = 0

        for i in range(1,amount + 1):
            for x in coins:
                if (x <= i):
                    dp[i] = min((dp[i - x] + 1),dp[i])

        if (dp[amount] != INT_MAX):
            return dp[amount]
        else:
            return -1

c = CoinChange()
coins1 = [1,2,5]
coins2 = [1,2,3,10]
amount1 = 11
amount2 = 25

result1 = c.begin(coins1,amount1)
print("coins1: {0}\nresult1: {1}".format(coins1,result1))
result2 = c.begin(coins2,amount2)
print("coins2: {0}\nresult2: {1}".format(coins2,result2))