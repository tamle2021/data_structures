'''
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting
them. A node can only appear in the sequence at most once. Note that path does not need to pass through root.

The path sum of a path is the sum of node's values in path.
Given root of a binary tree, return the maximum path sum of any non-empty path.

example:
                 12
               /   \
              4    35
                 /   \
                22   41

input: root = [12,4,35,null,null,22,41]
output: 42
explanation: The optimal path is 22 -> 35 -> 41 with a path sum of 98.

constraints:
Number of nodes in tree is in range [1,3 * 10^4].
-1000 <= node.val <= 1000

**** maximum path sum of binary tree ****

'''
# definition of binary tree node
class Node:
    def __init__(self,x):
        self.left = None
        self.right = None
        self.data = x

class BinaryTreeMaximumPathSum():
    result = -float("inf")
    # recursive
    def calculateMps(self,node):
        if (node is None):
            return 0
        left = self.calculateMps(node.left)
        right = self.calculateMps(node.right)

        mxSide = max(node.data,max(left,right) + node.data)
        mxTop = max(mxSide,left + right + node.data)
        self.result = max(self.result,mxTop)
        return mxSide

    def start(self,root: Node) -> int:
        self.calculateMps(root)
        return self.result

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

print("**** maximum path sum of binary tree ****")
b = BinaryTreeMaximumPathSum()
nodeList = []

tree = Node(12)
b.insert(tree,Node(4))
b.insert(tree,Node(35))
b.insert(tree,Node(22))
b.insert(tree,Node(41))

result = b.start(tree)
print("result: ",result)

nodeList = inOrder(tree,nodeList)
print("in-order: %s" % nodeList)