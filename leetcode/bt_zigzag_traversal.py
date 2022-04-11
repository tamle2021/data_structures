'''
Given root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left
to right, then right to left for next level and alternate between).

example 1:
             3
           /  \
          9   20
             /  \
            15  7

input:
root = [3,9,20,null,null,15,7]

output:
[[3],[20,9],[15,7]]

example 2:
input:
root = []

output:
[]

constraints:
The number of nodes in tree is the range [0,2000].
-100 <= Node.val <= 100


**** binary tree zigzag level-order traversal ****

'''
from typing import List
import collections

# definition of binary tree node
class Node():
    def __init__(self,x):
        self.left = None
        self.right = None
        self.data = x

class BtZigZagTraversal():
    def start(self,root: Node) -> List[List[int]]:
        if (not root):
            return []

        result = []
        deq = collections.deque()

        zigzag = False
        deq.append(root)

        while (deq):
            level = []
            for x in range(len(deq)):
                if (zigzag):
                    node = deq.pop()
                    level.append(node.data)

                    if (node.right):
                        deq.appendleft(node.right)
                    if (node.left):
                        deq.appendleft(node.left)
                else:
                    node = deq.popleft()
                    level.append(node.data)

                    if (node.left):
                        deq.append(node.left)
                    if (node.right):
                        deq.append(node.right)

            result.append(level)
            # flip the zig zag
            zigzag = not zigzag

        return result

    def insert(self,root,node):
        if (root is None):
            root = node
            return

        if (root.data < node.data):
            if (root.right is None):
                root.right = node
            else:
                self.insert(root.right,node)
        else:
            if (root.left is None):
                root.left = node
            else:
                self.insert(root.left,node)

def inOrder(node,nodeList):
    if (node is not None):
        inOrder(node.left,nodeList)
        nodeList.append(node.data)
        inOrder(node.right,nodeList)

    return nodeList

print("**** binary tree zigzag level-order traversal ****")
b = BtZigZagTraversal()
nodeList = []

tree = Node(36)
b.insert(tree,Node(19))
b.insert(tree,Node(62))
b.insert(tree,Node(45))
b.insert(tree,Node(71))

result = b.start(tree)
print("result: ",result)

nodeList = inOrder(tree,nodeList)
print("in-order: %s" % nodeList)





