'''
Count number of primes up to n
Sieve of Eratothenes: An algorithm for making tables of primes. Sequentially write down the integers
from 2 to the highest number n you wish to include in the table. Cross out all numbers > 2 which are
divisible by 2 (every second number). Find the smallest remaining number > 2. It is 3. So cross out all
numbers > 3 which are divisible by 3 (every third number). Find the smallest remaining number > 3.
It is 5. So cross out all numbers >5 which are divisible by 5 (every fifth number).

'''
import math

class CountPrimes:
    def start(self,n: int) -> int:
        if (n < 2):
            return 0
        isPrime = [True] * n
        isPrime[0] = isPrime[1] = False

        for i in range(2,math.ceil(math.sqrt(n))):
            if (isPrime[i]):
                for multiples_of_i in range(i * i,n,i):
                    isPrime[multiples_of_i] = False

        return sum(isPrime)

c = CountPrimes()
# 2,3,5,7
result = c.start(9)
print("number of primes: {y}".format(y=result))