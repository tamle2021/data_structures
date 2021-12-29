'''
Given an array of strings, group the anagrams together. One can return the answer in any order.  An anagram is a word or
phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

input: strs = ["eat","tea","tan","ate","nat","bat"]
output: [["bat"],["nat","tan"],["ate","eat","tea"]]

constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lower-case english letters

time complexity: O(N * M * log(M))
N => length of input array
M => length of largest string in array

**** group anagrams ****

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

print("**** group anagrams ****")
anagram1 = ["eat","tea","tan","ate","nat","bat"]
anagram2 = ["ant","tan","nat","tab","bat","sky","key","lap","ape","pea","eye","yee","soy","gin","pus","usp"]
g = GroupAnagrams()
result1 = g.begin(anagram1)
result2 = g.begin(anagram2)

print("input 1: {y}".format(y=anagram1))
print("output 1: %s" % result1)
print("input 2: {y}".format(y=anagram2))
print("output 2: %s" % result2)