'''
Doubly-linked list with deletion implementation
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

        # iterate for array length
        while (i < n):
            newNode = Node(arr[i])
            if (i == 0):
                start = newNode
                newNode.prev = start
                temp = start
            else:
                temp.next = newNode
                newNode.prev = temp
                temp = temp.next

            i = i + 1

        self.head = start
        return start

    def printList(self):
        temp = self.head
        linkedListStr = ""
        while (temp):
            linkedListStr += (str(temp.data) + " ")
            temp = temp.next
        print(linkedListStr)

    # count elements
    def countList(self):
        # temp pointer to traverse the list
        temp = self.head
        count = 0

        while (temp is not None):
            temp = temp.next
            count = count + 1

        return count

    # index to begin at 0
    def deleteAtLocation(self,index):
        temp = self.head
        count = self.countList()

        if (count < index):
            return temp

        if (index == 0):
            temp = temp.next
            self.head = temp
            return self.head

        if (count == index):
            while (temp.next is not None and temp.next.next is not None):
                temp = temp.next

            temp.next = None
            return self.head

        i = 0
        while (i < index - 1):
            temp = temp.next
            i += 1

        prevNode = temp
        nodeAtTarget = temp.next
        nextNode = nodeAtTarget.next
        nextNode.prev = prevNode
        prevNode.next = nextNode

        return self.head

print("**** doubly linked list with deletion ****")
arr = [5,11,-14,31,92,247]
doublyLinkedList = LinkedList()
doublyLinkedList.createList(arr)
doublyLinkedList.deleteAtLocation(3)
doublyLinkedList.printList()