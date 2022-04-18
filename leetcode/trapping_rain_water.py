'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
it can trap after raining.

# example 1
input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

output:
6

explanation:
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].  In this case, 6 units
of rain water are being trapped.

# example 2
input:
height = [4,2,0,3,2,5]

output:
9

constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

**** trapping rain water ****


'''
from typing import List

class TrappingRainWater():
    def begin(self,height: List[int]) -> int:
        n = len(height)
        if (n == 0):
            return 0

        left = [0] * n
        right = [0] * n
        result = 0

        left[0] = height[0]
        # maximize left side
        for i in range(1,n):
            left[i] = max(left[i - 1],height[i])

        right[n - 1] = height[n - 1]
        # start from right side
        for i in range(n - 2,-1,-1):
            right[i] = max(right[i + 1],height[i])

        for i in range(0,n):
            result += min(left[i],right[i]) - height[i]

        return result

print("**** trapping rain water ****")
t = TrappingRainWater()
height1 = [4,2,0,3,2,5]
height2 = [1,5,7,0,8,2,3,9]

result1 = t.begin(height1)
print("bar heights1: {0}\nresult1: {1}".format(height1,result1))

result2 = t.begin(height2)
print("bar heights2: {0}\nresult2: {1}".format(height2,result2))