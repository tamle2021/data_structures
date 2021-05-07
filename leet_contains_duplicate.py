'''
Checks for duplicate in array
'''

from collections import defaultdict
from typing import List

def containsDuplicate(nums: List[int]) -> bool:
    m = defaultdict(int)

    for num in nums:
        if m[num]:
            return True
        m[num] += 1
    return False

arr = [4,0,1,2,6,99,87,4]
result = containsDuplicate(arr)

if (result):
    print("contains duplicate...")
else:
    print("no duplicate...")