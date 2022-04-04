/*



**** graph traversal adjacency list ****

 */

package graph_traversal_adjacency_list;

import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
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
        g.addUndirectedEdge(1,2);
        g.addUndirectedEdge(3,2);
        g.addUndirectedEdge(4,3);
        g.addUndirectedEdge(5,1);

        System.out.println("**** graph traversal adjacency list ****");
        System.out.println(g.toString());
        System.out.println("breadth-first search:");
        g.bfs();
    }
}
