'''
Find first and last position of target number in sorted array

time complexity: O(log(n))
space complexity: O(1)
'''

from typing import List

class FirstLastPosition:
    def getLeftPosition(self,nums,target):
        left = 0
        right = len(nums) - 1

        while (left <= right):
            mid = left + (right - left)//2
            if (nums[mid] == target):
                if ((mid - 1) >= 0 and nums[mid-1] != target or mid == 0):
                    return mid
                right = mid - 1
            elif(nums[mid] > target):
                right = mid - 1
            else:
                left = mid + 1

        return -1

    def getRightPosition(self, nums, target):
        left = 0
        right = len(nums)-1

        while(left <= right):
            mid = left+(right-left)//2
            if(nums[mid] == target):
                if(mid+1 < len(nums) and nums[mid+1] != target or mid == len(nums)-1):
                    return mid
                left = mid+1
            elif(nums[mid] > target):
                right = mid-1
            else:
                left = mid+1

        return -1

    def searchRange(self,arr: List[int],target: int) -> List[int]:
        left = self.getLeftPosition(arr,target)
        right = self.getRightPosition(arr,target)

        return [left,right]

arr = [1,1,4,5,7,8,44,1,44,4,11,0,4]
arr.sort()
# after sort: [0,1,1,1,4,4,4,5,7,8,11,44,44]
target = 4

f = FirstLastPosition()
result = f.searchRange(arr,target)
print("first & last position: {y}".format(y=result))

