'''
Binary search tree with deletion

'''

class Node:
    def __init__(self,value):
        self.left = None
        self.right = None
        self.data = value

def insert(root,node):
    if (root is None):
        root = node
        return

    if (root.data < node.data):
        if (root.right is None):
            root.right = node
        else:
            insert(root.right,node)
    else:
        if (root.left is None):
            root.left = node
        else:
            insert(root.left, node)

def preorder(node):
    if (node is not None):
        print(node.data)
        preorder(node.left)
        preorder(node.right)

def minValueNode(node):
    while (node.left is not None):
        node = node.left
    return node

def deleteNode(node,key):
    if (node is None):
        return node
    # If the key to be deleted is smaller than the node's key, then it lies in left subtree.
    if (key < node.data):
        node.left = deleteNode(node.left, key)
    # If the key to be deleted is greater than the node's key, then it lies in right subtree.
    elif (key > node.data):
        node.right = deleteNode(node.right, key)
    # If key is same as node's key, then delete the node.
    else:
        # node with only one child or no child
        if (node.left is None):
            temp = node.right
            node = None
            return temp
        elif (node.right is None):
            temp = node.left
            node = None
            return temp

        # node with two children
        # get the inorder successor (smallest in the right subtree)
        temp = minValueNode(node.right)
        # copy the inorder successor's content to this node
        node.data = temp.data
        # delete the inorder successor
        node.right = deleteNode(node.right,temp.data)

    return node


#	         92
#         /  	\
#       44	     115
#     /   \     /   \
#    21    53  101   431
tree = Node(92)
insert(tree,Node(44))
insert(tree,Node(115))
insert(tree,Node(21))
insert(tree,Node(53))
insert(tree,Node(101))
insert(tree,Node(431))
deleteNode(tree,115)

#	         92
#         /  	 \
#       44	     431
#     /   \     /   \
#    21   53  101   None

# 92 44 21 53 431 101
preorder(tree)