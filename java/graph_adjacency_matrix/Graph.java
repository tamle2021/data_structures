/*
Graph is an abstract data type that is a representation of nodes and the connections between those nodes.

**** graph using adjacency matrix ****

*/
package graph_adjacency_matrix;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;

public class Graph {
  ArrayList<GraphNode> nodeList = new ArrayList<GraphNode>();
  int[][] adjacencyMatrix;

  public Graph(ArrayList<GraphNode> nodeList) {
    this.nodeList = nodeList;
    adjacencyMatrix = new int[nodeList.size()][nodeList.size()];
  }

  public void addUndirectedEdge(int i,int j) {
    adjacencyMatrix[i][j] = 1;
    adjacencyMatrix[j][i] = 1;
  }

  public String toString() {
    StringBuilder s = new StringBuilder();
    s.append("   ");

    for (int i = 0; i < nodeList.size(); i++) {
      s.append(nodeList.get(i).name + " ");
    }
    s.append("\n");

    for (int i = 0; i < nodeList.size(); i++) {
      s.append(nodeList.get(i).name + ": ");
      for (int j : adjacencyMatrix[i]) {
        s.append((j) + " ");
      }
      s.append("\n");
    }

    return s.toString();
  }

  public ArrayList<GraphNode> getNeighbors(GraphNode node) {
    ArrayList<GraphNode> neighbors = new ArrayList<GraphNode>();
    int nodeIndex = node.index;

    for (int i = 0; i < adjacencyMatrix.length; i++) {
      if (adjacencyMatrix[nodeIndex][i] == 1) {
        neighbors.add(nodeList.get(i));
      }
    }

    return neighbors;
  }

  // breadth-first search
  void bfsVisit(GraphNode node) {
    LinkedList<GraphNode> queue = new LinkedList<GraphNode>();
    queue.add(node);
    while (!queue.isEmpty()) {
      GraphNode currentNode = queue.remove(0);
      currentNode.isVisited = true;
      System.out.print(currentNode.name + " ");
      ArrayList<GraphNode> neighbors = getNeighbors(currentNode);

      for (GraphNode neighbor: neighbors) {
        if (!neighbor.isVisited) {
          queue.add(neighbor);
          neighbor.isVisited = true;
        }
      }
    }
  }

  public void bfs() {
    for (GraphNode node : nodeList) {
      if (!node.isVisited) {
        bfsVisit(node);
      }
    }
  }

  void dfsVisit(GraphNode node) {
    Stack<GraphNode> stack = new Stack<>();
    stack.push(node);

    while (!stack.isEmpty()) {
      GraphNode currentNode = stack.pop();
      currentNode.isVisited = true;
      System.out.print(currentNode.name + " ");
      ArrayList<GraphNode> neighbors = getNeighbors(currentNode);
      for (GraphNode neighbor : neighbors) {
        if (!neighbor.isVisited) {
          stack.push(neighbor);
          neighbor.isVisited = true;
        }
      }

    }
  }

  void dfs() {
    for (GraphNode node : nodeList) {
      if (!node.isVisited) {
        dfsVisit(node);
      }
    }
  }

  public static void main(String[] args) {
    System.out.println("**** graph using adjacency matrix ****");
    ArrayList<GraphNode> nodeList = new ArrayList<GraphNode>();
    nodeList.add(new GraphNode("A",0));
    nodeList.add(new GraphNode("B",1));
    nodeList.add(new GraphNode("C",2));
    nodeList.add(new GraphNode("D",3));
    nodeList.add(new GraphNode("E",4));
    nodeList.add(new GraphNode("F",5));

    Graph g = new Graph(nodeList);
    g.addUndirectedEdge(0,1);
    g.addUndirectedEdge(0,2);
    g.addUndirectedEdge(0,3);
    g.addUndirectedEdge(1,4);
    g.addUndirectedEdge(2,3);
    g.addUndirectedEdge(3,4);
    g.addUndirectedEdge(1,5);
    g.addUndirectedEdge(4,5);

    System.out.println(g.toString());



  }




}
