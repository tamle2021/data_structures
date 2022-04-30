/*
Breadth-first search algorithm is a graph traversing technique, where one selects a random initial node (source or root node)
and starts traversing the graph layer-wise in such a way that all the nodes and their children nodes are visited
and explored.


**** breadth-first search using queue ****

*/
#include <iostream>
#include <queue>

using namespace std;

void start(int vertex,int A[][8],int n) {
    queue<int> Q;
    int visited[8] {0};

    // visit vertex
    cout << vertex << " " << flush;
    visited[vertex] = 1;
    Q.emplace(vertex);

    // explore
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        // adjacent vertices of u
        for (int v = 1; v <= n; v++) {
		    // mark it visited if not and place in queue
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
    cout << "**** breadth-first search using queue ****\n";
    int A[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}};

    int vertex2 = 2;
    int vertex5 = 5;
    int vertex7 = 7;

    cout << "starting from vertex "  << vertex2 << ": "<< flush;
    start(vertex2,A,8);

    cout << "starting from vertex " << vertex5 << ": " << flush;
    start(vertex5,A,8);

    cout << "starting from vertex " << vertex7 << ": " << flush;
    start(vertex7,A,8);

    return 0;
}
