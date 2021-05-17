'''
Find the minimum number of boats to fit persons with weight
Individual weights must be less or equal than limit.
Each boat fits 2 or less persons.
Sum of persons' weight is less than or equal to limit.
'''

from typing import List

class NumRescueBoats:
    def start(self,people: List[int],limit: int) -> int:
        people.sort()

        left = 0
        right = len(people) - 1
        boats_number = 0

        while (left <= right):
            if (left == right):
                boats_number += 1
                break
            if (people[left] + people[right] <= limit):
                left += 1

            right -= 1
            boats_number += 1

        return boats_number

n = NumRescueBoats()
arr = [2,1,3,4]
numberBoats = n.start(arr,4)
print("number of boat(s): {0}".format(numberBoats))