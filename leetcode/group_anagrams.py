'''
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically
using all the original letters exactly once.  Another words, it is a permutation of letters to make a legal word,
where order matters.

Given an array of strings, group the anagrams together.

constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
'''
from typing import List

class GroupAnagrams:
    def findHash(self,s):
        return "".join(sorted(s))

    def begin(self,strs: List[str]) -> List[List[str]]:
        result = []
        m = {}

        for s in strs:
            hashed = self.findHash(s)
            if (hashed not in m):
                m[hashed] = []
            m[hashed].append(s)

        for p in m.values():
            result.append(p)

        return result

anagram1 = ["eat","tea","tan","ate","nat","bat"]
anagram2 = ["ant","tan","nat","tab","bat","sky","key","lap","ape","pea","eye","yee","soy","gin","pus","usp"]
g = GroupAnagrams()
result1 = g.begin(anagram1)
result2 = g.begin(anagram2)

print("input 1: {y}".format(y=anagram1))
print("output 1: %s" % result1)
print("input 2: {y}".format(y=anagram2))
print("output 2: %s" % result2)