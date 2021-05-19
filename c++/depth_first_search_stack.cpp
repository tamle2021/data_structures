/*
Depth first search using stack
*/

#include <iostream>
#include <stack>

using namespace std;

void DFS(int u, int A[][8], int n) {
    // initialize visit tracking array and stack
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);

    // visit start vertex u
    cout << u << ", " << flush;
    // visited vertex u
    visited[u] = 1;

    // initial adjacent vertex
    int v = 0;

    while (!stk.empty()){
        while (v < n){
            if (A[u][v] == 1 && visited[v] == 0){
                // suspend exploring current vertex u
                stk.push(u);
                // ipdate current vertex as the next adjacent vertex
                u = v;

                // visit current vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                // increment will make this 0
                v = -1;
            }
            v++;
        }
        // can set v = 0 but setting v = u is better
        v = u;
        // return to previous suspended vertex
        u = stk.top();
        stk.pop();
    }
}

// adds elements to stack from end
void dfs(int u, int A[][8], int n){
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);

    while (!stk.empty()){
        u = stk.top();
        stk.pop();

        if (visited[u] != 1){
            cout << u << ", " << flush;
            visited[u] = 1;

            for (int v=n-1; v>=0; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    stk.emplace(v);
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
    cout << "depth first search vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;

    u = 3;
    cout << "depth first search vertex: " << u << " -> " << flush;
    dfs(u, A, 8);
    cout << endl;

    return 0;
}
