'''
Singly-linked list with deletion implementation
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        linkedListStr = ""
        while (temp):
            linkedListStr += (str(temp.data) + " ")
            temp = temp.next
        print(linkedListStr)

    def deleteNode(self,key):
        temp = self.head
        if (temp is None):
            return
        if (temp.data == key):
            self.head = temp.next
            temp = None
            return

        while (temp.next.data != key):
            temp = temp.next

        targetNode = temp.next
        temp.next = targetNode.next
        targetNode.next = None

# list Structure : 55 => 11 => 92 => 25 => 14
linkedList = LinkedList()
linkedList.head = Node(55)
secondNode = Node(11)
thirdNode = Node(92)
fourthNode = Node(25)
fifthNode = Node(14)

linkedList.head.next = secondNode
secondNode.next = thirdNode
thirdNode.next = fourthNode
fourthNode.next = fifthNode

print("**** singly linked list with deletion ****")
print("before deletion: ")
linkedList.printList()
linkedList.deleteNode(25)
print("\nafter deletion: ")
linkedList.printList()