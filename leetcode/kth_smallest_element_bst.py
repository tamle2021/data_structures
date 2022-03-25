'''
Given root of a binary search tree and an integer k, return kth smallest value (1-indexed) of all nodes in tree.

example 1:
input: root = [3,1,4,null,2], k = 1
output: 1


constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4


**** kth smallest element in binary search tree ****

'''

class Node():
    def __init__(self,value):
        self.left = None
        self.right = None
        self.data = value

class KthSmallestElementBst():
    def start(self,root: Node,k: int) -> int:
        self.k = k
        self.result = None

        self.inOrder(root)
        return self.result

    def inOrder(self,root):
        if (not root):
            return

        self.inOrder(root.left)

        self.k -= 1
        if (self.k == 0):
            self.result = root.data
            return

        self.inOrder(root.right)

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



print("**** kth smallest element in binary search tree ****")
tree = Node(5)

k = KthSmallestElementBst()
k.insert(tree,Node(1))
k.insert(tree,Node(11))
k.insert(tree,Node(8))
k.insert(tree,Node(14))

print("preorder: [5,1,11,8,13]")
result = k.start(tree,4)
print("result: %s" % result)


#           5
#         /   \
#        1    11
#            /  \
#           8   13
