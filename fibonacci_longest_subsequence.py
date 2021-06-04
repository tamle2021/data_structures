'''
Longest length of fibonacci-like subsequence

Fibonacci sequence is a series of numbers where a number is the addition of the last two numbers, starting
with 0 and 1.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 .....

time complexity: O(n^2 * log(m)), where n is the length of array and m is maximum element
'''
class LongestFibSubSequence:
    def start(self,A,n):
        # store in hash table
        S = set(A)
        maxLength = 0

        for i in range(0,n):
            for j in range(i + 1,n):
                x = A[j]
                y = A[i] + A[j]
                length = 2

                # check until next fibonacci element is found
                while (y in S):
                    # next element of fibonacci subsequence
                    z = x + y
                    x = y
                    y = z
                    length += 1
                    maxLength = max(maxLength,length)

        if (maxLength >= 3):
            return maxLength
        else:
            return 0

arr1 = [1,3,7,11,12,14,18]
arr = [1,2,3,4,5,6,7,8]
n = len(arr)

l = LongestFibSubSequence()
result = l.start(arr,n)
print("result: ",result)
