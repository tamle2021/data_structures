'''



**** binary search tree creation & insertion ****

'''
class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

def insert(root, node):
    if (root is None):
        root = node
        return

    if (root.data < node.data):
        if (root.right is None):
            root.right = node
        else:
            insert(root.right, node)
    else:
        if(root.left is None):
            root.left = node
        else:
            insert(root.left, node)


def preOrder(node,nodeList):
    if (node is not None):
        # print(node.data)
        nodeList.append(node.data)
        preOrder(node.left,nodeList)
        preOrder(node.right,nodeList)

    return nodeList

def postOrder(node,nodeList):
    if (node is not None):
        postOrder(node.left,nodeList)
        postOrder(node.right,nodeList)
        nodeList.append(node.data)

    return nodeList

#	         21
#        /       \
#     10	       44
#   /   \       /     \
#  4     15    31       101

tree = Node(21)
#	         21
#       /  	      \
#     None	       None

insert(tree,Node(10))
#	      21
#      /  	 \
#     10	  None

insert(tree,Node(4))
#	        21
#       /  	    \
#     10        None
#   /
#  4

insert(tree,Node(15))
#	        21
#       /  	     \
#     10         None
#   /   \
#  4     15

insert(tree,Node(44))
#	        21
#       /  	    \
#     10         44
#   /   \
#  4     15

insert(tree,Node(31))
#	        21
#       /       \
#     10          44
#   /   \        /
#  4     15      31

insert(tree,Node(101))
#	        21
#       / 	     \
#     10	      44
#   /   \       /     \
#  4    15     31      101


print("**** binary search tree creation & insertion ****")
nodeList1 = []
nodeList2 = []
# 21 10 4 6 44 31 101

result1 = preOrder(tree,nodeList1)
print("pre-order: %s" % result1)

result2 = postOrder(tree,nodeList2)
print("post-order: %s" % result2)