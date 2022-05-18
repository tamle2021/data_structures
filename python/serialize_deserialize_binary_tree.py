'''



**** serialization & deserialization of binary tree ****

'''
# definition of binary tree node.
class Node(object):
    def __init__(self,x):
        self.left = None
        self.right = None
        self.data = x

class Codec():
    def serialize(self,root):
        # encodes tree to single string.
        if (root is None):
            return "Y#"

        leftSerialized = self.serialize(root.left)
        rightSerialized = self.serialize(root.right)

        return str(root.data) + "#" + leftSerialized + rightSerialized

    def deserialize(self,data):
        # decodes encoded data to tree.
        def dfs():
            d1 = next(data)
            if (d1 == 'Y'):
                return None
            node = Node(int(d1))

            node.left = dfs()
            node.right = dfs()

            return node

        data = iter(data.split("#"))
        return dfs()

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


def postOrder(node,nodeList):
    if (node is not None):
        postOrder(node.left,nodeList)
        postOrder(node.right,nodeList)
        nodeList.append(node.data)

    return nodeList


print("**** serialization & deserialization of binary tree ****")
c = Codec()
nodeList = []

tree = Node(26)
c.insert(tree,Node(13))
c.insert(tree,Node(72))
c.insert(tree,Node(6))
c.insert(tree,Node(14))
c.insert(tree,Node(35))

serialized = c.serialize(tree)
print("serialized data: {0}".format(serialized))

deserialized = c.deserialize(serialized)
print("deserialized data: {0}".format(deserialized))

nodeList = postOrder(tree,nodeList)
print("post-order: %s" % nodeList)







