'''
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.  According to the definition of LCA
on wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q
as descendants (where we allow a node to be a descendant of itself).”

input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
output: 3
explanation: The LCA of nodes 5 and 1 is 3.

constraints:
The number of nodes in the tree is in the range [2,10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree

**** lowest common ancestor binary tree ****

'''

# definition for a binary tree node
class Node:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class LowestCommonAncestor:
    def recurse(self,root: Node,p: Node,q: Node) -> Node:
        if (root is None):
            return None
        if (root.val == p.val or root.val == q.val):
            return root

        left = self.recurse(root.left,p,q)
        right = self.recurse(root.right,p,q)

        if (left is None and right is None):
            return None
        if (left is not None and right is not None):
            return root
        if (left is None):
            return right

        return left

# [3,5,1,6,2,0,8,null,null,7,4]
# creation of nodes and pre-order traversal
node3 = Node(3)
node5 = Node(5)
node1 = Node(1)
node6 = Node(6)
node2 = Node(2)
node0 = Node(0)
node8 = Node(8)
node7 = Node(7)
node4 = Node(4)

# assignment
node3.left = node5
node3.right = node1
node5.left = node6
node5.right = node2
node1.left = node0
node1.right = node8
node2.left = node7
node2.right = node4

l = LowestCommonAncestor()

print("**** lowest common ancestor binary tree ****")
result1 = l.recurse(node3,node5,node1)
result2 = l.recurse(node3,node0,node8)
print("result1: ",result1.val)
print("result2: ",result2.val)
