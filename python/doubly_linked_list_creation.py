'''


**** doubly-linked list creation ****

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
        # concatenate and move pointer
        while (temp):
            linkedListStr += (str(temp.data) + " ")
            temp = temp.next

        print(linkedListStr)

print("**** doubly-linked list creation ****")
arr1 = [4,6,11,-5,22,87,101]
arr2 = [0,-5,15,22,115,121,44,1]
doublyLinkedList = LinkedList()
doublyLinkedList.createList(arr1)
doublyLinkedList.printList()

doublyLinkedList.createList(arr2)
doublyLinkedList.printList()