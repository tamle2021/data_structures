'''
An adjacency list, also called an edge list, can be modeled as a representation of network.  Each edge in the network
is indicated by listing the pair of nodes that are connected.  The order of nodes matter in directed graph.

**** directed graph adjacency list  ****

'''
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def insertEdge(self,v1,v2):
        self.graph[v1].append(v2)

    def printGraph(self):
        for node in self.graph:
            for v in self.graph[node]:
                print(node,"->",v)

    def displayGraph(self):
        print(self.graph)

print("**** directed graph adjacency list ****")
g = Graph()
g.insertEdge(1,2)
g.insertEdge(2,3)
g.insertEdge(4,5)
g.insertEdge(1,4)
g.insertEdge(5,1)
g.insertEdge(5,9)
g.insertEdge(6,3)

g.printGraph()
g.displayGraph()