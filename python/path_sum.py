'''
Given the root of a binary tree and an integer target sum, return true if the tree has a root-to-leaf path such that
adding up all the values along the path equals target sum. A leaf is a node with no children.

input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
output: true

constraints:
The number of nodes in the tree is in the range [0,5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

**** path sum ****

'''

# definition for a binary tree node.
class Node:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class PathSum:
    def recurse(self,root,target,current):
        if (root is None):
            return False
        current += root.val
        if (current == target and root.left is None and root.right is None):
            return True

        return (self.recurse(root.right,target,current) or self.recurse(root.left,target,current))

    def hasPathSum(self,root: Node,target: int) -> bool:
        return self.recurse(root,target,0)


# [5,4,8,11,null,13,4,7,2,null,null,null,1]
# create nodes
node5 = Node(5)
node4 = Node(4)
node8 = Node(8)
node11 = Node(11)
node13 = Node(13)
node4_ = Node(4)
node7 = Node(7)
node2 = Node(2)
node1 = Node(1)

# assignment
node5.left = node4
node5.right = node8
node4.left = node11
node8.left = node13
node8.right = node4_
node11.left = node7
node11.right = node2
node4_.right = node1

print("**** path sum ****")
targetSum1 = 22
targetSum2 = 29

p = PathSum()
result1 = p.hasPathSum(node5,targetSum1)
print("has sum %s ?: %s" % (targetSum1,result1))
result2 = p.hasPathSum(node5,targetSum2)
print("has sum %s ?: %s" % (targetSum2,result2))