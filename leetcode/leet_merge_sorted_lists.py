'''
Merge two sorted lists
time complexity: O(n)
space complexity: O(1)
'''

# definition for singly-linked list
class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class MergeTwoLists:
    def start(self,l1: ListNode,l2: ListNode) -> ListNode:
        cur = ListNode(0)
        ans = cur

        while (l1 and l2):
            if (l1.val > l2.val):
                cur.next = l2
                l2 = l2.next
            else:
                cur.next = l1
                l1 = l1.next
            cur = cur.next

        # add remaining elements
        while (l1):
            cur.next = l1
            l1 = l1.next
            cur = cur.next

        while (l2):
            cur.next = l2
            l2 = l2.next
            cur = cur.next
        return ans.next

m = MergeTwoLists()
# list 1 => 1->2->4->5
l1_1 = ListNode(1)
l1_2 = ListNode(2)
l1_4 = ListNode(4)
l1_5 = ListNode(5)
l1_1.next = l1_2
l1_2.next = l1_4
l1_4.next = l1_5

# list 2 => 1->3->4
l2_1 = ListNode(1)
l2_3 = ListNode(3)
l2_4 = ListNode(4)
l2_1.next = l2_3
l2_3.next = l2_4

result = m.start(l1_1,l2_1)
while (result != None):
    print(result.val)
    result = result.next