/*
Depth first search is a tree-based graph traversal algorithm that is used to search a graph. Unlike breadth first
search, a DFS algorithm traverses a tree or graph from the parent vertex down to its children and
grandchildren vertices in a single path until it reaches the end.  When there are no more vertices to visit
in a path, the DFS algorithm will backtrack to a point where it can choose another path to take.  It will repeat
the process again until all vertices have been visited.

Depth first search using stack structure
*/

#include <iostream>
#include <stack>

using namespace std;

void DFS(int u, int A[][8],int n) {
    // initialize visit tracking array and stack
    int visited[8] {0};
    stack<int> stac;
    stac.emplace(u);

    // visit start vertex u
    cout << u << ", " << flush;
    // visited vertex u
    visited[u] = 1;

    // initial adjacent vertex
    int v = 0;

    while (!stac.empty()){
        while (v < n){
            if (A[u][v] == 1 && visited[v] == 0){
                // suspend exploring current vertex u
                stac.push(u);
                // ipdate current vertex as the next adjacent vertex
                u = v;

                // visit current vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                // increment will make 0
                v = -1;
            }
            v++;
        }
        // can set v = 0 but setting v = u is better
        v = u;
        // return to previous suspended vertex
        u = stac.top();
        stac.pop();
    }
}

// adds elements to stack from end
void dfs(int u, int A[][8], int n){
    int visited[8] {0};
    stack<int> stac;
    stac.emplace(u);

    while (!stac.empty()){
        u = stac.top();
        stac.pop();

        if (visited[u] != 1){
            cout << u << ", " << flush;
            visited[u] = 1;

            for (int v = n - 1; v >= 0; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    stac.emplace(v);
                }
            }
        }
    }
}

int main (){
    int A[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}};

    int u = 5;
    cout << "*****depth first search*****\n";
    cout << "vertex: " << u << " => " << flush;
    DFS(u,A,8);
    cout << endl;

    u = 3;
    cout << "vertex: " << u << " => " << flush;
    dfs(u,A,8);
    cout << endl;

    return 0;
}
