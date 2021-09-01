'''
Pre-order traversal is the type of traversal in which we first visit the root node of the
tree. After the root node, we visit left subtree and then visit right
subtree. The pre-order traversal is mainly used to create copy of existing tree.
It is also used in the evaluation of expression.  For example, we can create a prefix
form of an expression using pre-order traversal.
'''

class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

def preorder(node):
    if(node is not None):
        print(node.data)
        preorder(node.left)
        preorder(node.right)

# create root
root = Node(12)
''' following is the tree after above statement 
	    12
	   /  \ 
	None  None
'''

root.left = Node(18)
root.right = Node(3)
''' 18 and 3 become left and right children of 12
		           12 
		         /     \ 
		       18	     3 
	         /   \     /   \ 
            None None None  None
'''

root.left.left = Node(32)
'''
32 becomes left child of 18
		           12 
		         /     \ 
		       18	     3 
	         /   \     /   \ 
            32   None None  None
'''

root.right.left = Node(-4)
'''
-4 becomes left child of 3
		           12 
		         /     \ 
		       18	     3 
	         /   \     /   \ 
            32   None -4   None
'''
preorder(root)
