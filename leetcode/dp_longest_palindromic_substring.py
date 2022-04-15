'''
Given a string s, return longest palindromic substring in s.  Palindrome string reads the same in both forward
and backward directions.

# example 1
input:
s = "babad"

output:
"bab"

explanation:
"aba" is also a valid answer.

# example 2
input:
s = "cbbd"

output:
"bb"

constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.


**** longest palindromic substring ****
*** dynamic programming ***


'''
class LongestPalindromicSubstring():
    def begin(self,s: str) -> str:
        n = len(s)
        if (n < 2):
            return s
        left = 0
        right = 0

        # initialize n x n matrix
        palindrome = [[0] * n for i in range(n)]

        for j in range(1,n):
            for i in range(0,j):
                innerIsPalindrome = palindrome[i + 1][j - 1] or j - i <= 2
                if (s[i] == s[j] and innerIsPalindrome):
                    palindrome[i][j] = True
                    if (j - i > right - left):
                        left = i
                        right = j

        return s[left:right + 1]

print("**** longest palindromic substring ****")
l = LongestPalindromicSubstring()
str1 = "babad"
str2 = "124924ipeepi"

result1 = l.begin(str1)
print(f"string1: {str1}\nresult1: {result1}")
result2 = l.begin(str2)
print(f"string2: {str2}\nresult2: {result2}")