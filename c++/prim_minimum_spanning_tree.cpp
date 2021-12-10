/*
A minimum spanning tree is a special kind of tree that minimizes the lengths or "weights" of tree edges.  A tree has one path that joins
any two vertices.  An example is a cable company that wants to lay line in multiple neighborhoods.  By minimizing the amount of
cable laid, the cable company will save money.

A spanning tree of a graph is a tree that contains all the original graph’s vertices, reaches out to or spans all vertices, and is
acyclic.  In other words, the graph does not have any nodes which loop back to itself.

*** prim's minimum spanning tree ****

*/
#include <iostream>
#define V 8
#define I 32767

using namespace std;

void printMST(int T[][V-2],int G[V][V]) {
    cout << "minimum spanning tree edges with cost: " << endl;
    int sum {0};
    for (int i {0}; i < V - 2; i++) {
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "total cost of minimum spanning tree: " << sum << endl;
}

void primMinimumSpanT(int G[V][V],int n) {
    int u;
    int v;
    int min {I};
    int track [V];
    int T[2][V-2] {0};

    // find min cost edge
    for (int i {1}; i < V; i++) {
        // initialize track array with infinity
        track[i] = I;
        for (int j {i}; j < V; j++) {
            if (G[i][j] < min) {
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }

    T[0][0] = u;
    T[1][0] = v;
    track[u] = track[v] = 0;

    // initialize array to track min cost edges
    for (int i {1}; i < V; i++) {
        if (track[i] != 0) {
            if (G[i][u] < G[i][v]) {
                track[i] = u;
            }
            else {
                track[i] = v;
            }
        }
    }

    // repeat
    for (int i {1}; i < n - 1; i++) {
        int k;
        min = I;
        for (int j {1}; j < V; j++) {
            if (track[j] != 0 && G[j][track[j]] < min) {
                k = j;
                min = G[j][track[j]];
            }
        }

        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;

        // update array to track min cost edges
        for (int j {1}; j < V; j++) {
            if (track[j] != 0 && G[j][k] < G[j][track[j]]) {
                track[j] = k;
            }
        }
    }
    printMST(T,G);
}

int main() {
    int cost [V][V] {
            {I,I,I,I,I,I,I,I},
            {I,I,25,I,I,I,5,I},
            {I,25,I,12,I,I,I,10},
            {I,I,12,I,8,I,I,I},
            {I,I,I,8,I,16,I,14},
            {I,I,I,I,16,I,20,18},
            {I,5,I,I,I,20,I,I},
            {I,I,10,I,14,18,I,I},
    };

    cout << "**** prim's minimum spanning tree ****\n";
    int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;

    primMinimumSpanT(cost,n);

    return 0;
}
