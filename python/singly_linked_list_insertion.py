'''
Singly-linked list with insertion implementation
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
        linked_list = ""
        while(temp):
            linked_list += (str(temp.data) + " ")
            temp = temp.next
        print(linked_list)

    # list start at 0
    def insertNode(self,value,position):
        target = Node(value)
        if (position == 0):
            target.next = self.head
            self.head = target
            return

        def getPrev(position):
            temp = self.head
            count = 1
            while (count < position):
                temp = temp.next
                count += 1
            return temp

        prev = getPrev(position)
        nextNode = prev.next
        prev.next = target
        target.next = nextNode

# list Structure : 11 => 9 => 72 => 1 => 55
print("**** linked list with insertion ****")
linkedList = LinkedList()
linkedList.head = Node(11)
secondNode = Node(9)
thirdNode = Node(72)
fourthNode = Node(1)
fifthNode = Node(55)

linkedList.head.next = secondNode
secondNode.next = thirdNode
thirdNode.next = fourthNode
fourthNode.next = fifthNode

print("before insertion: ")
linkedList.printList()
print("")
linkedList.insertNode(99,4)
print("after insertion: ")
linkedList.printList()