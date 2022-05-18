'''
The main difference between directed and undirected graph is that a directed graph contains
an ordered pair of vertices whereas an undirected graph contains an unordered pair of vertices.


**** undirected graph adjacency list ****

'''
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def insertEdge(self,v1,v2):
        self.graph[v1].append(v2)
        self.graph[v2].append(v1)

    def printGraph(self):
        for node in self.graph:
            # loop over lists corresponding to key
            for v in self.graph[node]:
                print(node,"->",v)

    def displayGraph(self):
        print("graph: %s" % self.graph)

print("**** undirected graph adjacency list ****")
g = Graph()
g.insertEdge(1,5)
g.insertEdge(5,1)
g.insertEdge(1,2)
g.insertEdge(2,3)
g.insertEdge(4,5)
g.insertEdge(5,4)
g.insertEdge(3,6)

g.printGraph()
g.displayGraph()