/*
Depth-first search is an algorithm for searching a graph or tree data structure. The algorithm starts at the root (top) node of a tree
and goes as far as it can down a given branch or path, then backtracks until it finds an unexplored path, and then explores it. The algorithm
does this until the entire graph has been explored. Many problems in computer science can be thought of in terms of graphs.

*** using recursion ***

*/
#include <iostream>

using namespace std;

void depthFirstSearch(int u,int A[][8],int n) {
    static int visited[8] {0};

    if (visited[u] == 0) {
        cout << u << " " << flush;
        visited[u] = 1;
        for (int v = 1; v < n; v++) {
            if (A[u][v] == 1 && visited[v] == 0) {
                depthFirstSearch(v,A,n);
            }
        }
    }
}

int main () {
    int A[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0,1,0,1,0,1,0,0},
        {0,0,0,1,1,0,1,1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0,0,0,0,0,1,0,0}};

    cout << "depth first search using recursion: \n";
    cout << "vertex 4: " << flush;
    depthFirstSearch(4,A,8);
    cout << endl;

    return 0;
}
