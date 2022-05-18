'''
Given the root of a binary tree, check whether it is a mirror of itself or symmetric around its center

input: root = [1,2,2,3,4,4,3]
output: true

input: root = [1,2,2,null,3,null,3]
output: false

constraints:
The number of nodes in the tree is in the range [1,1000].
-100 <= Node.val <= 100


**** symmetric tree ****
'''

# definition for a binary tree node
class Node:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class SymmetricTree:
    def isMirror(self,t1,t2):
        if (t1 is None and t2 is None):
            return True
        if (t1 is None or t2 is None):
            return False
        return (t1.val == t2.val) and self.isMirror(t1.right,t2.left) and self.isMirror(t1.left,t2.right)

    def isSymmetric(self,root: Node) -> bool:
        return self.isMirror(root,root)

# [1,2,2,3,4,4,3]
# create tree
node1 = Node(1)
node2 = Node(2)
node2_ = Node(2)
node3 = Node(3)
node4 = Node(4)
node4_ = Node(4)
node3_ = Node(3)
# assignment
node1.left = node2
node1.right = node2_
node2.left = node3
node2.right = node4
node2_.left = node4_
node2_.right = node3_

# assign another tree
node1_ = node1

print("**** symmetric tree ****")
s = SymmetricTree()
result1 = s.isMirror(node1_, node1)
result2 = s.isSymmetric(node1)

print("is mirror ? {y}".format(y=result1))
print("is symmetric ? {0}".format(result2))
