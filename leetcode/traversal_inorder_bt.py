'''
In inorder traversal, root node is visited in between it’s left and right child.
In this type of traversal, first entry is the leftmost node present in the the tree, last entry is
the rightmost node present in the the tree, and root node cannot be identified.

process for inorder:
1) visit the left subtree of root
2) visit the root
3) visit the right subtree of root
'''

class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

def inorder(node):
    if(node is not None):
        inorder(node.left)
        print(node.data)
        inorder(node.right)

# create root
root = Node(37)
''' following is the tree after above statement 
	    37 
	  /   \ 
	None  None
'''

root.left = Node(2)
root.right = Node(66)
''' 2 and 66 become left and right children of 37 
		          37 
		        /   \ 
		      2	     66 
	        /  \     /  \ 
          None None None None
'''

root.left.left = Node(0)
'''
0 becomes left child of 2
		         37 
		        /   \ 
		      2	     66 
	        /  \     /  \ 
           0   None None None
'''

root.right.right = Node(227)
'''
227 becomes right child of 66
		         37 
		        /   \ 
		      2	      66 
	        /  \     /  \ 
           0   None None 227
'''
inorder(root)