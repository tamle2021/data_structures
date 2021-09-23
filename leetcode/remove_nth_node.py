'''
Given head of a linked list, remove nth node from end of list and return its head.

input: head = [1,2,3,4,5], n = 2
output: [1,2,3,5]

constraints:
Number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


'''
# definition for singly-linked list
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class RemoveNthNodeFromEnd:
    def begin(self,head: ListNode,n: int) -> ListNode:
        result = ListNode(0)
        result.next = head

        first = result
        second = result

        for i in range(1,n + 2):
            first = first.next

        while (first is not None):
            first = first.next
            second = second.next

        second.next = second.next.next
        return result.next

r = RemoveNthNodeFromEnd()
node44 = ListNode(44)
node3 = ListNode(3)
node9 = ListNode(9)
node11 = ListNode(11)
node77 = ListNode(77)
node30 = ListNode(30)

node44.next = node3
node3.next = node9
node9.next = node11
node11.next = node77
node77.next = node30

result = r.begin(node44,3)
print("before removal: [44, 3, 9, 11, 77, 30]")

resultList = []
while (result != None):
    resultList.append(result.val)
    result = result.next
print("after removal: %s" % resultList)