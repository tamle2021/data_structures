'''
Binary search tree with search

'''

class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

def insert(root, node):
    if(root is None):
        root = node
        return

    if(root.data < node.data):
        if(root.right is None):
            root.right = node
        else:
            insert(root.right,node)
    else:
        if(root.left is None):
            root.left = node
        else:
            insert(root.left,node)

def search(node,key):
    print("current node: ",node.data)
    if (node is None):
        print("no node found...")
        return None
    if(node.data == key):
        print("node found...")
        return node

    if (node.data < key):
        return search(node.right,key)

    return search(node.left,key)

#	           44
#            /    \
#          21	  133
#        /   \   /   \
#       7    25 51   203
tree = Node(44)
insert(tree,Node(21))
insert(tree,Node(133))
insert(tree,Node(7))
insert(tree,Node(25))
insert(tree,Node(51))
insert(tree,Node(203))

nodeResult = search(tree,7)
print("found node data: %s" % nodeResult.data)