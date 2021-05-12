'''
Adjacency list - undirected graph implementation
'''

from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        # v1 => [v2,v3,v4]

    def insertEdge(self,v1,v2):
        self.graph[v1].append(v2)
        self.graph[v2].append(v1)

    def printGraph(self):
        # loop over keys
        for node in self.graph:
            # loop over lists corresponding to key
            for v in self.graph[node]:
                print(node,"->",v)

    def displayGraph(self):
        print("graph: %s" % self.graph)

g = Graph()
g.insertEdge(1,5)
g.insertEdge(1,100)
g.insertEdge(1,2)
g.insertEdge(2,3)
g.insertEdge(4,5)

g.printGraph()
g.displayGraph()