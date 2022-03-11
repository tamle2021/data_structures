'''
Given a string s, partition s such that every substring of the partition is a palindrome.  Return all possible palindrome
partitioning of s.  A palindrome string is a string that reads the same backward as forward.

example 1:
input: s = "aab"
output: [["a","a","b"],["aa","b"]]

example 2:
input: s = "b"
output: [["b"]]

constraints:
1 <= s.length <= 16
s contains only lowercase english letters

**** palindrome partitioning ****

'''
from typing import List

class PalindromePartioning:
    def isPalindrome(self,seg):
        i = 0
        j = len(seg) - 1

        while(i < j):
            if (seg[i] != seg[j]):
                return False
            i += 1
            j -= 1

        return True

    def depthFirstSearch(self,s: str):
        if (len(s) == 0 and len(self.temp) > 0):
            self.res.append(self.temp[:])
            return
        n = len(s) + 1

        for i in range(1,n):
            seg = s[0:i]
            if (self.isPalindrome(seg)):
                self.temp.append(seg)
                self.depthFirstSearch(s[i:])
                self.temp.pop()

    def begin(self,s: str) -> List[List[str]]:
        self.res = []
        self.temp = []
        self.depthFirstSearch(s)

        return self.res

if (__name__ == "__main__"):
    print("**** palindrome partitioning ****")
    p = PalindromePartioning()

    input1 = "ccd"
    input2 = "xyyz"
    result1 = p.begin(input1)
    result2 = p.begin(input2)

    print("input: {x}\nresult: {y}".format(x=input1,y=result1))
    print("")
    print("input: {x}\nresult: {y}".format(x=input2,y=result2))
