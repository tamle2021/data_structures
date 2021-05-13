'''
Depth first search using stack
time complexity: O(V + E)
space complexity: O(V)
'''

from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def insertEdge(self,v1,v2):
        self.graph[v1].append(v2)

    def depthFirstSearch(self,startNode):
        visited = set()
        stack = []
        stack.append(startNode)

        while (len(stack)):
            cur = stack[-1]
            stack.pop()

            if (cur not in visited):
                print(cur,end=" ")
                visited.add(cur)

            for vertex in self.graph[cur]:
                if (vertex not in visited):
                    stack.append(vertex)

    def printGraph(self):
        print("graph: {0}".format(self.graph))

g = Graph()
g.insertEdge(2,1)
g.insertEdge(2,5)
g.insertEdge(5,6)
g.insertEdge(5,8)
g.insertEdge(6,9)

# start at node 2
g.depthFirstSearch(2)
print("\n")
g.printGraph()