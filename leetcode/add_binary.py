'''
Given two binary strings a and b, return their sum as a binary string.

constraints:
1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

'''


class AddBinary(object):
    def beginProcess(self,a,b):
        result = []
        carry = 0
        i = len(a) - 1
        j = len(b) - 1

        while (i >= 0 or j >= 0 or carry):
            total = carry

            if (i >= 0):
                total += int(a[i])
                i -= 1
            if (j >= 0):
                total += int(b[j])
                j -= 1

            result.append(str(total % 2))
            carry = total//2

        return ''.join(reversed(result))

a = AddBinary()
result1 = a.beginProcess("1010","1011")
print("result one:",result1)

result2 = a.beginProcess("110","010")
print("result two: {x}".format(x=result2))