'''
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of non-zero
elements.  Note that you must do this in-place without making a copy of the array.
time complexity: O(2 * n) = O(n)
space complexity: O(1)

'''

from typing import List

class MoveZeroes:
    def start(self,arr: List[int]) -> None:
        j = 0
        for num in arr:
            if (num != 0):
                arr[j] = num
                j += 1
        # set rest of elements to zero
        for x in range(j, len(arr)):
            arr[x] = 0

        return arr

m = MoveZeroes()
arr = [111,0,77,0,52,0,3,5,0,9,11,-14,0,0,91,54,0]
print("before move: %s" % arr)
arr1 = m.start(arr)
print("after move: %s" % arr1)