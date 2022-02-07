'''
Given head of singly linked list, group all nodes with odd indices followed by grouping nodes
with even indices, and return re-ordered list.  The first node is odd, second node is even, third is odd, and so on.
Note that relative order inside both the even and odd groups should remain as it was in the input.

input: head = [2,1,3,5,6,4,7]
output: [2,3,6,7,1,5,4]

constraints:
n == number of nodes in linked list
0 <= n <= 10^4
-10^6 <= node.val <= 10^6

**** odd-even list ****

'''
# definition for singly-linked list
class Node:
    def __init__(self,x):
        self.val = x
        self.next = None

class OddEvenList:
    def start(self,head: Node) -> Node:
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

print("**** odd-even list ****")
node12 = Node(12)
node35 = Node(35)
node44 = Node(44)
node67 = Node(67)
node111 = Node(111)
node3 = Node(3)
node0 = Node(0)

# node links
node12.next = node35
node35.next = node44
node44.next = node67
node67.next = node111
node111.next = node3
node3.next = node0

beforeList = []
# assignment of head node
node = node12
while (node != None):
    beforeList.append(node.val)
    node = node.next

print("before: %s" % beforeList)

afterList = []
o = OddEvenList()
result = o.start(node12)
while (result != None):
    afterList.append(result.val)
    result = result.next

print("after: ",afterList)

