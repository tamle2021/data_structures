'''
Given head of a linked list, remove nth node from end of list and return its head.

input: head = [1,2,3,4,5], n = 2
output: [1,2,3,5]

constraints:
Number of nodes in list is size.
1 <= size <= 30
0 <= node.val <= 100
1 <= n <= size

**** remove nth node from end of list ****

'''
# definition for singly-linked list
class Node:
    def __init__(self,x):
        self.val = x
        self.next = None

class RemoveNthNodeFromEnd:
    def begin(self,head: Node,n: int) -> Node:
        result = Node(0)
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

print("**** remove nth node from end of list ****")
r = RemoveNthNodeFromEnd()
node43 = Node(43)
node3 = Node(3)
node9 = Node(9)
node11 = Node(11)
node77 = Node(77)
node25 = Node(25)

node43.next = node3
node3.next = node9
node9.next = node11
node11.next = node77
node77.next = node25

beforeList = []
nodeBefore = node43
while (nodeBefore != None):
    beforeList.append(nodeBefore.val)
    nodeBefore = nodeBefore.next
print("before: %s" % beforeList)

afterList = []
nodeAfter = node43

result = r.begin(node43,3)
while (nodeAfter != None):
    afterList.append(nodeAfter.val)
    nodeAfter = nodeAfter.next
print("after: %s" % afterList)