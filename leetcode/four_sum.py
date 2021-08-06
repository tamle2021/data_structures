'''
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of
tuples (i, j, k, l) such that: 0 <= i, j, k, l < n and nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

example 1:
input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
output: 2
explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

example 2:
input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
output: 1

constraints:
n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
'''
from typing import List

class FourSum:
    def begin(self,A: List[int],B: List[int],C: List[int], D: List[int]) -> int:
        m = {}
        result = 0

        for i in range(0,len(A)):
            x = A[i]
            for j in range(0,len(B)):
                y = B[j]
                if ((x + y) not in m):
                    m[x + y] = 0

                m[x + y] += 1

        for i in range(0,len(C)):
            x = C[i]
            for j in range(0,len(D)):
                y = D[j]
                target = -(x + y)

                if (target in m):
                    result += m[target]

        return result

numbers1 = [1,2]
numbers2 = [-2,-1]
numbers3 = [-1,2]
numbers4 = [0,2]

f = FourSum()
result = f.begin(numbers1,numbers2,numbers3,numbers4)
print("result: %s" % result)