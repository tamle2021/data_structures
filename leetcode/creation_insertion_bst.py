'''
Binary search tree with creation and insertion.

'''
class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

def insert(root,node):
    if (root is None):
        root = node
        return

    if(root.data < node.data):
        if (root.right is None):
            root.right = node
        else:
            insert(root.right,node)
    else:
        if (root.left is None):
            root.left = node
        else:
            insert(root.left,node)

def preorder(node):
    if (node is not None):
        print(node.data)
        preorder(node.left)
        preorder(node.right)


tree = Node(45)
'''
45 is the root
	        45
          /    \
        None   None
'''
insert(tree,Node(19))
'''
19 is the left child of 45
            45
          /    \
        19     None
'''

insert(tree,Node(11))
'''
11 is the left child of 19
            45
          /    \
        19     None
      /   \
    11    None
'''
insert(tree,Node(26))
'''
26 is the right child of 19
            45
          /    \
        19     None
      /   \
    11    26
'''
insert(tree,Node(99))
'''
99 is the right child of 45
            45
          /    \
        19     99
      /   \   /   \
    11    26 None  None
'''
insert(tree,Node(57))
'''
57 is the left child of 99
            45
          /    \
        19     99
      /   \   /   \
    11    26 57   None
'''
insert(tree,Node(317))
'''
317 is the right child of 99
            45
          /    \
        19     99
      /   \   /   \
    11    26 57   317
'''

preorder(tree)