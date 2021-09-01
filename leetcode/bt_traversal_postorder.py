'''
Post-order algorithm:
1. Traverse the left subtree
2. Traverse the right subtree
3. Visit the root.

usages of post-order:
Postorder traversal is used to delete the tree. Postorder traversal is also useful to get
postfix expression of an expression tree.

'''

class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

def postorder(node):
    if (node is not None):
        postorder(node.left)
        postorder(node.right)
        print(node.data)


# create root
root = Node(21)
''' following is tree after above statement 
	   21 
	  /   \ 
	None  None
'''

root.left = Node(1)
root.right = Node(53)
''' 1 and 53 become left and right children of 21
                   21
		        /      \ 
		       1        53
	          /  \      /   \ 
            None None  None  None
'''

root.left.left = Node(-7)
'''
                   21
		        /      \ 
		       1        53
	          /  \      /   \ 
             -7  None  None  None
'''

root.right.right = Node(191)
'''
191 becomes the right child of 92
	               44
		        /       \ 
		       25        92
	          /  \      /   \ 
             3  None  None  191
'''

postorder(root)
