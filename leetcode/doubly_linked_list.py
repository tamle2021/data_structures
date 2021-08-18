'''
Doubly-linked list implementation
'''
class Node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def createList(self,arr):
        start = self.head
        n = len(arr)

        temp = start
        i = 0
        while (i < n):
            newNode = Node(arr[i])
            if (i == 0):
                start = newNode
                temp = start
            else:
                temp.next = newNode
                newNode.prev = temp
                temp = temp.next
            i += 1
        self.head = start
        return start

    def printList(self):
        temp = self.head
        linkedListStr = ""
        # concatenate and move the pointer
        while (temp):
            linkedListStr += (str(temp.data) + " ")
            temp = temp.next

        print(linkedListStr)

arr = [4,6,11,-5,22,87,101]
print("**** doubly-linked list ****")
doublyLinkedList = LinkedList()
doublyLinkedList.createList(arr)
doublyLinkedList.printList()