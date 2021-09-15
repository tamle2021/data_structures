'''
Given the head of a singly linked list, reverse the list, and return the reversed list.



'''

# definition for singly-linked list
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class ReverseLinkedList:
    def begin(self,head: ListNode) -> ListNode:
        node = None
        while (head is not None):
            next = head.next
            head.next = node
            node = head
            head = next
        return node

r = ReverseLinkedList()
node11 = ListNode(11)
node52 = ListNode(52)
node37 = ListNode(37)
node12 = ListNode(12)
node94 = ListNode(94)

node11.next = node52
node52.next = node37
node37.next = node12
node12.next = node94

result = r.begin(node11)
while (result != None):
    print(result.val)
    result = result.next