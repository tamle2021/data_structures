'''
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that
every character in t (including duplicates) is included in the window. If there is no such substring, return the
empty string "".  A substring is a contiguous sequence of characters within the string.

example 1:
input: s = "ADOBECODEBANC", t = "ABC"
output: "BANC"
explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

example 2:
input: s = "a", t = "a"
output: "a"
explanation: The entire string s is the minimum window.

example 3:
input: s = "a", t = "aa"
output: ""
explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase english letters

**** minimum window substring ****

'''
class MinimumWindowSubstring:
    def start(self,s: str,t: str) -> str:
        len1 = len(s)
        len2 = len(t)

        if(len1 < len2):
            return ""

        hashPattern = {}
        hashString = {}
        for i in range(0,len2):
            if(hashPattern.get(t[i]) is None):
                hashPattern[t[i]] = 0
            hashPattern[t[i]] += 1

        count = 0
        left = 0
        startIndex = -1
        minLen = float("inf")

        for right in range(0,len1):
            if (hashString.get(s[right]) is None):
                hashString[s[right]] = 0
            hashString[s[right]] += 1

            if(hashPattern.get(s[right]) is None):
                hashPattern[s[right]] = 0
            if (hashPattern.get(s[right]) != 0 and hashString.get(s[right]) <= hashPattern.get(s[right])):
                # keep incrementing count if string hash is less then pattern hash
                count += 1
            # count == len2 means a window is found that contains all character of pattern string
            if (count == len2):
                if (hashString.get(s[left]) is None):
                    hashString[s[right]] = 0
                if (hashPattern.get(s[left]) is None):
                    hashPattern[s[right]] = 0
                while (hashString.get(s[left]) > hashPattern.get(s[left]) or hashPattern.get(s[left]) == 0):
                    # minimize windows range from left side
                    if (hashString.get(s[left]) > hashPattern.get(s[left])):
                        hashString[s[left]] -= 1
                    # increment left pointer
                    left += 1

                # calculate windows length
                windowLen = right - left + 1
                if (minLen > windowLen):
                    minLen = windowLen
                    startIndex = left

        if (startIndex == -1):
            return ""
        return s[startIndex:startIndex+minLen]


m = MinimumWindowSubstring()
print("**** minimum window substring **** ")
s1 = "ADOBECODEBXANCEE"
t1 = "ABC"
result1 = m.start(s1,t1)
print("s1: %s" % s1)
print("t1: %s" % t1)
print("result 1: {0}\n".format(result1))

s2 = "92xbbcz21qrstttty"
t2 = "xyz"
result2 = m.start(s2,t2)
print("s2: %s" % s2)
print("t2: %s" % t2)
print("result 2: {0}".format(result2))

