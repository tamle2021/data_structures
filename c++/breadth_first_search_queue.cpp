/*
Breadth first search algorithm is a graph traversing technique, where one selects a random initial node (source or root node) and starts
traversing the graph layer-wise in such a way that all the nodes and their respective children nodes are visited and explored.
Breadth first search using queue
FIFO
*/
#include <iostream>
#include <queue>

using namespace std;

void BFS(int vtx,int A[][8],int n) {
    queue<int> Q;
    int visited[8] {0};

    // visit vertex
    cout << vtx << " " << flush;
    visited[vtx] = 1;
    Q.emplace(vtx);

    // explore
    while (!Q.empty()) {
        // vertex u for exploring
        int u = Q.front();
        Q.pop();
        // adjacent vertices of vertex u
        for (int v = 1; v <= n; v++) {
		    // adjacent vertex and not visited
            if (A[u][v] == 1 && visited[v] == 0) {
                cout << v << " " << flush;
                // visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main () {
    int A[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "*****breadth first search*****\n";
    cout << "v1: " << flush;
    BFS(1, A, 8);

    cout << "v3: " << flush;
    BFS(3, A, 8);

    cout << "v4: " << flush;
    BFS(4, A, 8);

    return 0;
}