'''
The adjacency matrix of a simple labeled graph is the matrix A with A [[i,j]] or 0 according to whether the
vertex vj, is adjacent to the vertex vj or not. For simple graphs without self-loops, the adjacency matrix has zeros
on the diagonal. For undirected graphs, the adjacency matrix is symmetric.

**** directed graph adjacency matrix ****

'''
from collections import defaultdict

class Graph:
    def __init__(self,numberOfNodes):
        self.numberOfNodes = numberOfNodes + 1
        self.graph = [[0 for x in range(numberOfNodes + 1)]
            for y in range(numberOfNodes + 1)]

    def withInBounds(self,v1,v2):
        return (v1 >= 0 and v1 <= self.numberOfNodes) and (v2 >= 0 and v2 <= self.numberOfNodes)

    def insertEdge(self,v1,v2):
        if (self.withInBounds(v1,v2)):
            self.graph[v1][v2] = 1

    def printGraph(self):
        for i in range(self.numberOfNodes):
            for j in range(len(self.graph[i])):
                if (self.graph[i][j]):
                    print(i, "->", j)

    def displayGraph(self):
        print("graph: {0}".format(self.graph))

print("**** directed graph adjacency matrix ****")
g = Graph(6)
g.insertEdge(1,2)
g.insertEdge(2,3)
g.insertEdge(4,5)
g.insertEdge(1,3)
g.insertEdge(5,2)
g.insertEdge(5,1)
g.insertEdge(6,4)

g.printGraph()
g.displayGraph()