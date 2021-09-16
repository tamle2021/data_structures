'''
One is given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
One may assume the two numbers do not contain any leading zeros, except the number 0 itself.

example:
input => l1 = [2,4,3], l2 = [5,6,4]
output => [7,0,8]
explanation => 342 + 465 = 807.

constraints:
Number of nodes in each linked list is in the range [1,100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

space and time complexity: O(n)
'''

# definition for singly-linked list
class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class AddTwoNumbers:
    def beginProcess(self,l1: ListNode,l2: ListNode) -> ListNode:
        ans = ListNode(None)
        pointer = ans
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
            pointer.next = ListNode(sum % 10)

            pointer = pointer.next

        if (carry > 0):
            pointer.next = ListNode(carry)

        return ans.next

a = AddTwoNumbers()
# first list
linkedList1Node5 = ListNode(5)
linkedList1Node6 = ListNode(6)
linkedList1Node1 = ListNode(1)
linkedList1Node7 = ListNode(7)
# connect
linkedList1Node5.next = linkedList1Node6
linkedList1Node6.next = linkedList1Node1
linkedList1Node1.next = linkedList1Node7

# second list
linkedList2Node8 = ListNode(8)
linkedList2Node9 = ListNode(9)
linkedList2Node3 = ListNode(3)
linkedList2Node2 = ListNode(2)
# connect
linkedList2Node8.next = linkedList2Node9
linkedList2Node9.next = linkedList2Node3
linkedList2Node3.next = linkedList2Node2

result = a.beginProcess(linkedList1Node5,linkedList2Node8)
while (result != None):
    print(result.val)
    result = result.next

