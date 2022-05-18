'''
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right,
level by level).

example 1:
             3
           /  \
          9   20
             /  \
            15   7

input: root = [3,9,20,null,null,15,7]
output: [[3],[9,20],[15,7]]

constraints:
The number of nodes in tree is in range [0,2000].
-1000 <= node.val <= 1000


**** binary tree level-order traversal ****

'''
# definition of binary tree node.
from collections import deque
from typing import List

class Node():
    def __init__(self,x):
        self.left = None
        self.right = None
        self.data = x

class BtLevelOrderTraversal():
    def levelOrder(self,root: Node) -> List[List[int]]:
        result = []
        if (root is None):
            return result

        q = deque([root])
        while (q):
            n = len(q)
            temp = []
            for i in range(0,n):
                f = q.popleft()
                temp.append(f.data)

                if (f.left is not None):
                    q.append(f.left)
                if (f.right is not None):
                    q.append(f.right)

            if (len(temp) > 0):
                result.append(temp[:])
                temp.clear()

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

def preOrder(node,nodeList):
    if (node is not None):
        nodeList.append(node.data)
        preOrder(node.left,nodeList)
        preOrder(node.right,nodeList)

    return nodeList

print("**** binary tree level-order traversal ****")
b = BtLevelOrderTraversal()
nodeList = []

tree = Node(26)
b.insert(tree,Node(13))
b.insert(tree,Node(51))
b.insert(tree,Node(4))
b.insert(tree,Node(37))
b.insert(tree,Node(91))

result = b.levelOrder(tree)
print("result: ",result)

nodeList = preOrder(tree,nodeList)
print("pre-order: %s" % nodeList)
