'''
Given an integer n, return the number of prime numbers that are strictly less than n.

# example 1
input:
n = 10

output:
4

explanation:
There are 4 prime numbers less than 10 and they are 2, 3, 5, 7.

# example 2
input:
n = 0

output:
0

# example 3
input:
n = 1

output:
0

----------------------------------------------------------------------------------------------------------------------
Sieve of eratosthenes is algorithm for making tables of primes.  Sequentially write down integers from 2 to highest
number n one wishes to include in table.  Cross out all numbers > 2 which are divisible by 2 (every second number).
Find smallest remaining number > 2 and it is 3.  Then, cross out all numbers > 3 which are divisible by 3 (every third
number).  Find smallest remaining number > 3 and it is 5.  Then, cross out all numbers > 5 which are divisible by 5
(every fifth number).

**** count primes ****


'''
import math

class CountPrimes():
    def start1(self,number: int) -> int:
        if (number < 2):
            return 0

        # initialize array
        isPrime = [True] * number
        # zero and one are not considered primes
        isPrime[0] = isPrime[1] = False

        for i in range(2,math.ceil(math.sqrt(number))):
            if (isPrime[i]):
                for multiplesOfI in range(i * i,number,i):
                    isPrime[multiplesOfI] = False

        return sum(isPrime)

    # brute force; time complexity: O(n^2)
    def start2(self,number: int) -> int:
        if (number < 2):
            return 0

        primeArr = [True] * number
        primeArr[0] = primeArr[1] = False

        for i in range(2,number):
            # iterate back till 1
            for x in range(i - 1,1,-1):
                # if (x == 1):
                #     break
                # not prime if divisible
                if (i % x == 0):
                    primeArr[i] = False
                    break

        return sum(primeArr)


print("**** count primes ****")
c = CountPrimes()
n1 = 10
n2 = 15
n3 = 5

result1 = c.start1(n1)
print("number1: {0}\nresult1: {1}".format(n1,result1))

result2 = c.start2(n2)
print("number2: {0}\nresult2: {1}".format(n2,result2))

result3 = c.start2(n3)
print("number3: {0}\nresult3: {1}".format(n3,result3))


