'''
Given root of a binary tree, return the post-order traversal of its nodes' values.

example 1:
     1
      \
      2
     /
    3


input:
root = [1,null,2,3]

output:
[3,2,1]

example 2:
input:
root = []

output:
[]

constraints:
The number of nodes in tree is in range [0,100].
-100 <= node.val <= 100


**** binary tree post-order traversal ****

'''
from typing import List

class Node():
    def __init__(self,x):
        self.left = None
        self.right = None
        self.data = x


class BtPostOrderTraversal():
    # using stacks
    def begin(self,root: Node) -> List[int]:
        if (not root):
            return

        result = []
        stack1 = []
        stack2 = []

        stack1.append(root)

        while (stack1):
            x = stack1[-1]
            stack1.pop()
            stack2.append(x)

            if (x.left):
                stack1.append(x.left)
            if (x.right):
                stack1.append(x.right)

        while (stack2):
            y = stack2[-1]
            stack2.pop()
            result.append(y.data)

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

def postOrder(node,nodeList):
    if (node is not None):
        postOrder(node.left,nodeList)
        postOrder(node.right,nodeList)
        nodeList.append(node.data)

    return nodeList

print("**** binary tree post-order traversal ****")
b = BtPostOrderTraversal()
nodeList = []

tree = Node(21)
b.insert(tree,Node(15))
b.insert(tree,Node(84))
b.insert(tree,Node(7))
b.insert(tree,Node(18))

result = b.begin(tree)
print("result: ",result)

nodeList = postOrder(tree,nodeList)
print("post-order: %s" % nodeList)

