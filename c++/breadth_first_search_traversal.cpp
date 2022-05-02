/*


**** breadth-first search traversal ****

*/
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// directed graph using adjacency list
class Graph {
    // number of vertices
    int V;

    // pointer to an array containing adjacency lists
    vector<list<int>> adj;
public:
    // constructor
    Graph(int V);

    // function to add an edge to graph
    void addEdge(int v,int w);

    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v,int w) {
    // add w to v’s list
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    // initialize vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);

    list<int> queue;

    // mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        // dequeue a vertex from queue
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // find adjacent vertices of the dequeued vertex, mark it visited if unvisited, and enqueue it
        for (auto adjacent: adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main() {
    cout << "**** breadth-first search traversal ****\n";

    int node2 = 2;
    int node0 = 0;

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);

    cout << "starting from node " << node2 << ": ";
    g.BFS(node2);
    cout << endl;

    cout << "starting from node " << node0 << ": ";
    g.BFS(node0);

    return 0;
}
