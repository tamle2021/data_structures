'''
Singly-linked list implementation

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
        while(temp):
            linkedListStr += (str(temp.data) + " ")
            temp = temp.next
        print(linkedListStr)

# node strucutre: 5 => 29 => 3 => 7 => 11
print("**** singly linked list ****")
linkedList = LinkedList()
linkedList.head = Node(5)
second_node = Node(29)
third_node = Node(3)
fourthNode = Node(7)
fifthNode = Node(11)

linkedList.head.next = second_node
second_node.next = third_node
third_node.next = fourthNode
fourthNode.next = fifthNode
linkedList.printList()