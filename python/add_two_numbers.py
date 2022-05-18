'''
One is given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
order and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
One may assume the two numbers do not contain any leading zeros, except the number 0 itself.

example:
input: l1 = [2,4,3], l2 = [5,6,4]
output: [7,0,8]
explanation: 342 + 465 = 807.

constraints:
Number of nodes in each linked list is in the range [1,100].
0 <= Node.val <= 9
It is guaranteed that list represents a number that does not have leading zeros.

space and time complexity: O(n)

**** add two numbers ****

'''

# definition for singly-linked list
class Node:
    def __init__(self,x):
        self.val = x
        self.next = None

class AddTwoNumbers:
    def start(self,l1: Node,l2: Node) -> Node:
        ans = Node(None)
        pointer:Node = ans
        carry = 0
        sum = 0

        while (l1 != None or l2 != None):
            sum = carry
            if (l1 != None):
                sum += l1.val
                l1 = l1.next
            if (l2 != None):
                sum += l2.val
                l2 = l2.next

            carry = int(sum / 10)
            pointer.next = Node(sum % 10)
            pointer = pointer.next

        if (carry > 0):
            pointer.next = Node(carry)

        return ans.next

# not adding up correctly
print("**** add two numbers ****")
a = AddTwoNumbers()
# first list
linkedList1Node5 = Node(5)
linkedList1Node6 = Node(6)
linkedList1Node1 = Node(1)
linkedList1Node7 = Node(7)
# connection
linkedList1Node5.next = linkedList1Node6
linkedList1Node6.next = linkedList1Node1
linkedList1Node1.next = linkedList1Node7

# second list
linkedList2Node8 = Node(8)
linkedList2Node9 = Node(9)
linkedList2Node3 = Node(3)
linkedList2Node2 = Node(2)
# connection
linkedList2Node8.next = linkedList2Node9
linkedList2Node9.next = linkedList2Node3
linkedList2Node3.next = linkedList2Node2

result = a.start(linkedList1Node5,linkedList2Node8)
# print(result)
while (result != None):
    print(result.val)
    result = result.next


