'''
A doubly-linked list contains two pointers and a data element.

**** doubly-linked list insertion ****

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
        while (temp):
            linkedListStr += (str(temp.data) + " ")
            temp = temp.next

        return linkedListStr

    def countList(self):
        temp = self.head
        count = 0
        while (temp is not None):
            temp = temp.next
            count += 1
        return count

    # index to begin at 0
    def insertAtLocation(self,value,index):
        temp = self.head
        count = self.countList()

        if (count + 1 < index):
            return temp

        newNode = Node(value)

        if (index == 0):
            newNode.next = temp
            temp.prev = newNode
            self.head = newNode
            return self.head

        if (index == count + 1):
            while (temp.next is not None):
                temp = temp.next

            temp.next = newNode
            newNode.prev = temp
            return self.head

        i = 0
        while (i < index - 1):
            temp = temp.next
            i += 1

        nodeAtTarget = temp.next
        newNode.next = nodeAtTarget
        nodeAtTarget.prev = newNode

        temp.next = newNode
        newNode.prev = temp
        return self.head

print("**** doubly-linked list insertion ****")
arr = [5,45,111,23,77,41]

appendStr = ""
for i in arr:
    appendStr += str(i) + " "
print("before insertion: ",appendStr)

doublyLinkedList = LinkedList()
doublyLinkedList.createList(arr)
doublyLinkedList.insertAtLocation(92,4)
doublyLinkedList.insertAtLocation(-6,1)
print("after insertion: ",doublyLinkedList.printList())

