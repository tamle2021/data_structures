'''
Longest substring without repeating characters
'''

class LongestSubstringNoRepeat:
    def start(self,s: str) -> int:
        m = {}
        left = 0
        right = 0
        ans = 0
        n = len(s)
        while (left < n and right < n):
            el = s[right]
            if (el in m):
                left = max(left,m[el] + 1)
            m[el] = right
            ans = max(ans,right - left + 1)
            right += 1
        return ans

l = LongestSubstringNoRepeat()
result = l.start("blueskydown")
print("result: ",result)