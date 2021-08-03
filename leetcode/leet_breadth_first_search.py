'''
Breadth-first search starts by searching a start node, followed by its adjacent nodes, then all nodes that can be
reached by a path from the start node containing two edges, three edges, four edges, etc.
time complexity: O(V + E)
space complexity: O(V)
'''
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def setEdge(self,u,v):
        self.graph[u].append(v)

    def bfs(self, s):
        visited = set()
        queue = []
        queue.append(s)

        visited.add(s)
        while queue:
            u = queue.pop(0)
            print(u,end=" ")

            for v in self.graph[u]:
                if v not in visited:
                    queue.append(v)
                    visited.add(v)

g = Graph()
g.setEdge(2,1)
g.setEdge(2,5)
g.setEdge(3,4)
g.setEdge(3,2)
g.setEdge(4,6)
g.setEdge(5,6)
g.setEdge(5,8)
g.setEdge(5,9)
g.setEdge(6,7)
g.setEdge(6,9)

print("**** breadth first search ****")
g.bfs(2)