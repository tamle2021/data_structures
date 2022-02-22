'''
Given a string containing digits from 2-9 inclusive, return all possible letter combinations the
number could represent and in any order.  A mapping of digits to letters is similar to telephone buttons
and 1 does not map to any letters.

example 1:
input: digits = "23"
output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

example 2:
input: digits = ""
output: []

example 3:
input: digits = "2"
output: ["a","b","c"]

constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']

**** phone number letter combinations ****

'''
from typing import List

class LetterCombinations:
    def backtracking(self,ans,m,digits,combination,index):
        if (index > len(digits)):
            return
        if (len(combination) == len(digits)):
            ans.append(combination[:])
            return

        currentDigit = digits[index]
        curString = m[currentDigit]

        for i in range(len(curString)):
            self.backtracking(ans,m,digits,combination + curString[i],index + 1)

    def begin(self,digits: str) -> List[str]:
        answer = []
        if (len(digits) == 0):
            return answer

        m = {}
        m['2'] = "abc"
        m['3'] = "def"
        m['4'] = "ghi"
        m['5'] = "jkl"
        m['6'] = "mno"
        m['7'] = "pqrs"
        m['8'] = "tuv"
        m['9'] = "wxyz"

        self.backtracking(answer,m,digits,"",0)
        return answer

print("**** phone number letter combinations ****")
number = "35"
l = LetterCombinations()
result = l.begin(number)

print("number: {0}\ncombination(s): {1}".format(number,result))