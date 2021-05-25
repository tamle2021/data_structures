'''
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in linked list if there is some node in list that can be reached again by continuously
following the next pointer.

checks to see if linked list has a cycle
'''

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class HasCycle:
    def start(self,head: ListNode) -> bool:
        hare = head
        turtle = head

        while (turtle and hare and hare.next):
            hare = hare.next.next
            turtle = turtle.next
            if (turtle == hare):
                return True
        return False

h = HasCycle()
node1 = ListNode(1)
node5 = ListNode(5)
node11 = ListNode(11)
node8 = ListNode(8)
node9 = ListNode(9)

node1.next = node5
node5.next = node11
node11.next = node8
node8.next = node9
node9.next = node5

result = h.start(node1)
print("has cycle: {0}".format(result))