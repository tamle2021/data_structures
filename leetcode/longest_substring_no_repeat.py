'''
space complexity: O(n)

**** longest substring without repeating characters ****
'''

class LongestSubstringNoRepeat:
    def start(self,s: str) -> int:
        m = {}
        left = 0
        right = 0
        result = 0
        n = len(s)
        while (left < n and right < n):
            element = s[right]
            if (element in m):
                left = max(left,m[element] + 1)
            m[element] = right
            result = max(result,right - left + 1)
            right += 1
        return result

l = LongestSubstringNoRepeat()
print("**** longest substring without repeating characters *****")
first = "bluesbbbblues"
second = "abaxday"
firstResult = l.start(first)
secondResult = l.start(second)
print("first result of {0}: {1}".format(first,firstResult))
print("second result of {0}: {1}".format(second,secondResult))