'''
Number of occurrences greater than n/2 equals majority element.
'''

from typing import List
majorityFlag = False

def majorityElement(arr: List[int]) -> int:
    global majorityFlag
    m = {}
    for num in arr:
        m[num] = m.get(num,0) + 1
    for num in arr:
        if (m[num] > len(arr) // 2):
            majorityFlag = True
            return num

arr = [4,2,1,0,0,0]
result = majorityElement(arr)

if (majorityFlag):
    print("majority element: %s" %  result)
else:
    print("no majority...")