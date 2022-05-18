'''
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of
tuples (i, j, k, l) such that 0 <= i, j, k, l < n and nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

example 1:
input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
output: 2

two tuples:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

constraints:
n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28

time complexity: O(n^2)
space complexity: O(n)

*** non-optimal method ***
**** four sum ****

'''
from typing import List

class FourSum():
    def begin(self,A: List[int],B: List[int],C: List[int], D: List[int]) -> int:
        result = 0

        for i in range(0,len(A)):
            for j in range(0,len(B)):
                for k in range(0,len(C)):
                    for l in range (0,len(D)):
                        if (A[i] + B[j] + C[k] + D[l] == 0):
                            result +=1

        return result

num1 = [1,2]
num2 = [-2,-1]
num3 = [-1,2]
num4 = [0,2]

num5 = [0,2]
num6 = [-1,3]
num7 = [1,-1]
num8 = [-2,1]

print("**** four sum ****")
f = FourSum()
print(f"arrays1: num1 = [1,2], num2 = [-2,-1], num3 = [-1,2], num4 = [0,2]")
result1 = f.begin(num1,num2,num3,num4)
print("result1: %s" % result1)

print(f"arrays2: num5 = [0,2], num6 = [-1,3], num7 = [1,-1], num8 = [-2,1]")
result2 = f.begin(num5,num6,num7,num8)
print("result2: %s" % result2)
