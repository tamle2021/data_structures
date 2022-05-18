'''
Given the root of a binary tree, return its maximum depth.  A binary tree's maximum depth is the number of nodes along
the longest path from the root node down to the farthest leaf node.  Height of tree is not same as maximum depth.

input: root = [3,9,20,null,null,15,7]
output: 3

input: root = [1,null,2]
output: 2

constraints:
The number of nodes in the tree is in the range [0,104].
-100 <= Node.val <= 100



**** maximum depth binary tree ****

'''

# definition of binary tree node
class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class MaximumDepthBinaryTree:
    def recurse(self,root: Node) -> int:
        if (root is None):
            return 0
        if (root.left is None and root.right is None):
            return 1

        left = self.recurse(root.left)
        right = self.recurse(root.right)

        return max(left,right) + 1

# [3,9,22,null,null,16,8]
# root node is the beginning
node3 = Node(3)
node9 = Node(9)
node22 = Node(22)
node16 = Node(16)
node8 = Node(8)

node3.left = node9
node3.right = node22
node22.left = node16
node22.right = node8

print("**** maximum depth of binary tree ****")
m = MaximumDepthBinaryTree()
result = m.recurse(node3)
print("depth of tree: %s" % result)