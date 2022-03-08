 /*
Graphs come in different forms such as simple graph, undirected or directed graph, cyclic or acyclic graph, labeled graph,
weighted graph, and infinite graph.

**** graph using adjacency list ****

*/
  package graph_adjacency_list;

  import java.util.*;

  public class Graph {
    ArrayList<GraphNode> nodeList = new ArrayList<GraphNode>();

    public Graph(ArrayList<GraphNode> nodeList) {
      this.nodeList = nodeList;
    }

    public void addUndirectedEdge(int i,int j) {
      GraphNode first = nodeList.get(i);
      GraphNode second = nodeList.get(j);

      first.neighbors.add(second);
      second.neighbors.add(first);
    }

  // print graph to console
    public String toString() {
      StringBuilder s = new StringBuilder();

      for (int i = 0; i < nodeList.size(); i++) {
        s.append(nodeList.get(i).name + ": ");

        for (int j = 0; j < nodeList.get(i).neighbors.size(); j++) {
          if (j == nodeList.get(i).neighbors.size() - 1 ) {
            s.append((nodeList.get(i).neighbors.get(j).name) );
          }
          else {
            s.append((nodeList.get(i).neighbors.get(j).name) + " -> ");
          }
        }
        s.append("\n");
      }
      return s.toString();
    }

    // bfs internal
    void bfsVisit(GraphNode node) {
      LinkedList<GraphNode> queue = new LinkedList<GraphNode>();
      queue.add(node);

      while (!queue.isEmpty()) {
        GraphNode currentNode = queue.remove(0);
        currentNode.isVisited = true;
        System.out.print(currentNode.name + " ");

        for (GraphNode neighbor : currentNode.neighbors) {
          if (!neighbor.isVisited) {
            queue.add(neighbor);
            neighbor.isVisited = true;
          }
        }
      }
    }

    void bfs() {
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

        for (GraphNode neighbor : currentNode.neighbors) {
          if (!neighbor.isVisited) {
            stack.push(neighbor);
            neighbor.isVisited=true;
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
      System.out.println("**** graph using adjacency list ****");

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
      g.addUndirectedEdge(5,1);
      g.addUndirectedEdge(5,2);

      System.out.println(g.toString());
    }

  }
