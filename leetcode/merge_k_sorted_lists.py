'''
One is given an array of k-linked lists of lists and each linked list is sorted in ascending order.
Merge all the linked lists into one sorted linked-list and return it.

input: lists = [[1,4,5],[1,3,4],[2,6]]
output: [1,1,2,3,4,4,5,6]
the linked lists are [1->4->5, 1->3->4, 2->6]
merging them into one sorted list => 1->1->2->3->4->4->5->6

constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order
The sum of lists[i].length will not exceed 10^4.

'''
from typing import List

# definition for singly-linked list
class Node:
    def __init__(self,x):
        self.val = x
        self.next = None

class MergeKLists:
    def mergeTwoLists(self,l1,l2):
        cur = Node(0)
        ans = cur

        while (l1 and l2):
            if (l1.val > l2.val):
                cur.next = l2
                l2 = l2.next
            else:
                cur.next = l1
                l1 = l1.next
            cur = cur.next

        while (l1):
            cur.next = l1
            l1 = l1.next
            cur = cur.next
        while (l2):
            cur.next = l2
            l2 = l2.next
            cur = cur.next
        return ans.next

    def startProcess(self,lists: List[Node]) -> Node:
        if (len(lists) == 0):
            return None

        i = 0
        last = len(lists) - 1
        j = last

        while (last != 0):
            i = 0
            j = last

            while (j > i):
                lists[i] = self.mergeTwoLists(lists[i],lists[j])
                i += 1
                j -= 1
                last = j

        return lists[0]

print("**** merge k sorted lists ****")
m = MergeKLists()
# sorted lists => [[2,4,9,11],[3,5,7,15],[6,12,18]]
linkedList1Node2 = Node(2)
linkedList1Node4 = Node(4)
linkedList1Node9 = Node(9)
linkedList1Node11 = Node(11)
# link nodes
linkedList1Node2.next = linkedList1Node4
linkedList1Node4.next = linkedList1Node9
linkedList1Node9.next = linkedList1Node11

linkedList2Node3 = Node(3)
linkedList2Node5 = Node(5)
linkedList2Node7 = Node(7)
linkedList2Node15 = Node(15)
# link nodes
linkedList2Node3.next = linkedList2Node5
linkedList2Node5.next = linkedList2Node7
linkedList2Node7.next = linkedList2Node15

linkedList3Node6 = Node(6)
linkedList3Node12 = Node(12)
linkedList3Node18 = Node(18)
# link nodes
linkedList3Node6.next = linkedList3Node12
linkedList3Node12.next = linkedList3Node18

sortedLists = []
resultList = []
beforeList = []
sortedLists.append(linkedList1Node2)
sortedLists.append(linkedList2Node3)
sortedLists.append(linkedList3Node6)

for i in sortedLists:
    while (i != None):
        beforeList.append(i.val)
        i = i.next
print("before:",beforeList)

result = m.startProcess(sortedLists)
while (result != None):
    resultList.append(result.val)
    result = result.next
print("after: {0}".format(resultList))