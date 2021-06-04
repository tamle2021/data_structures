'''
Valid mountain array consists of increasing sequence followed by decreasing.


'''
from typing import List

class ValidMountainArray:
    def start(self,A: List[int]) -> bool:
        if (len(A) < 3):
            return False

        i = 1
        # check for increasing sequence
        while (i < len(A) and A[i] > A[i - 1]):
            i += 1

        if (i == 1 or i == len(A)):
            return False

        # check for decreasing sequence
        while (i < len(A) and A[i] < A[i - 1]):
            i += 1

        return i == len(A)

v = ValidMountainArray()
result = v.start([1,1,2,3,1])
print("result: {x}".format(x=result))


