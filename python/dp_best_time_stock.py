'''
One is given an array prices where prices[i] is price of stock on ith day.  One wants to maximize profit by
choosing a single day to buy one stock and choosing a different day in future to sell that stock.  Return maximum
profit one can achieve from this transaction. If cannot achieve any profit, return 0.

# example 1
input:
prices = [7,1,5,3,6,4]

output:
5

explanation:
Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit => 6 - 1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

# example 2
input:
prices = [7,6,4,3,1]

output: 0

explanation:
In this case, no transactions are done and the max profit = 0.

constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4


**** best time to buy & sell stock ****
*** dynamic programming ***

'''
from typing import List

class BestTimeStock():
    def start(self,prices: List[int]) -> int:
        buyPrice = float("inf")
        profit = 0

        for i,price in enumerate(prices):
            # get minimum price
            if (buyPrice > price):
                buyPrice = price
            else:
                profit = max(profit,price - buyPrice)

        return profit

print("**** best time to buy & sell stock ****")
b = BestTimeStock()
pricesArr1 = [4,2,1,2,3,15,10]
pricesArr2 = [16,4,4,1]

result1 = b.start(pricesArr1)
print(f"prices1: {pricesArr1}\nprofit1: {result1}")

result2 = b.start(pricesArr2)
print(f"prices2: {pricesArr2}\nprofit2: {result2}")