'''
Given a string s containing characters '(', ')', '{', '}', '[' and ']', determine if the input string
is valid.

An input string is valid if open brackets are closed by similar type of brackets and open brackets are closed in
correct order.

example 1:
input: s = "()"
output: true

example 2:
input: s = "()[]{}"
output: true

example 3:
input: s = "(]"
output: false

constraints:
1 <= s.length <= 10^4
s consists of parentheses of '()[]{}'

**** valid parentheses ****

'''
class ValidParentheses():
    def isEqual(self,p1,p2) -> bool:
        if (p1 == '(' and p2 == ')'):
            return True
        if (p1 == '[' and p2 == ']'):
            return True
        if (p1 == '{' and p2 == '}'):
            return True

        return False

    def isValid(self,s: str) -> bool:
        stack = []

        for character in s:
            if (len(stack) != 0):
                curChar = stack[-1]
                if (self.isEqual(curChar,character)):
                    stack.pop()
                    continue

            stack.append(character)

        return len(stack) == 0

print("**** valid parentheses ****")
v = ValidParentheses()
str1 = "([]})"
str2 = "{[{()}]}"

result1 = v.isValid(str1)
print(f"string1: {str1}\nresult1: {result1}")
result2 = v.isValid(str2)
print(f"string2: {str2}\nresult2: {result2}")

