/*
Breadth first search using queue.
FIFO
explore all edges of vertex
*/

#include <iostream>
#include <queue>

using namespace std;

void BFS(int vtx, int A[][8], int n){
    queue<int> Q;
    int visited[8] {0};

    // visit vertex
    cout << vtx << ", " << flush;
    visited[vtx] = 1;
    Q.emplace(vtx);

    // explore
    while (!Q.empty()){
        // vertex u for exploring
        int u = Q.front();
        Q.pop();
        // adjacent vertices of vertex u
        for (int v=1; v<=n; v++){
		    // adjacent vertex and not visited
            if (A[u][v] == 1 && visited[v] == 0){
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main (){
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "vertex: 1 -> " << flush;
    BFS(1, A, 8);

    cout << "vertex: 4 -> " << flush;
    BFS(4, A, 8);

    return 0;
}
