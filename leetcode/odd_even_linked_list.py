'''
Given the head of a singly linked list, group all the nodes with odd indices together followed by nodes
with even indices, and return the reordered list.
The first node is odd, second node is even, third is odd, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.

input: head = [2,1,3,5,6,4,7]
output: [2,3,6,7,1,5,4]

constraints:
n == number of nodes in the linked list
0 <= n <= 10^4
-10^6 <= Node.val <= 10^6
'''

# definition for singly-linked list
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class OddEvenList:
    def start(self,head: ListNode) -> ListNode:
        if (not head):
            return head

        odd = head
        even = odd.next
        evenList = even

        while (even and even.next):
            odd.next = even.next
            odd = odd.next

            even.next = odd.next
            even = even.next

        odd.next = evenList
        return head

print("**** odd even linked list ****")
node12 = ListNode(12)
node35 = ListNode(35)
node44 = ListNode(44)
node67 = ListNode(67)
node111 = ListNode(111)

# node links
node12.next = node35
node35.next = node44
node44.next = node67
node67.next = node111

beforeList = []
# assignment of head node
node = node12
while (node != None):
    beforeList.append(node.val)
    node = node.next

print("before: %s" % beforeList)

o = OddEvenList()
result = o.start(node12)
oddEvenList = []

while (result != None):
    oddEvenList.append(result.val)
    result = result.next

print("after: ",oddEvenList)

