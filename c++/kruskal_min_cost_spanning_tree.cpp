/*
A minimum spanning tree is one that contains the least weight among all other spanning trees of a connected weighted graph.  There
can be more than one minimum spanning tree for a graph.  Kruskal’s algorithm is an approach to find the minimum
spanning tree in a connected graph.

The algorithm finds a subset of a graph G such that it forms a tree with every vertex in it and the sum of weights is the minimum among
all the spanning trees that can be formed from this graph.
The sequence of steps for Kruskal’s algorithm is given as follows:
1) First sort all edges from the lowest weight to highest.
2) Take edge with the lowest weight and add it to the spanning tree.  If a cycle is created, discard the edge.
3) Keep adding edges in step one until all vertices are considered.

**** kruskal minimum cost spanning tree ****

*/
#include <iostream>

// infinity
#define I 32767
// number of vertices in graph
#define V 7
 // number of edges in graph
#define E 9

using namespace std;

void printMinCostSpaningTree(int T[][V - 1],int A[][E]) {
    cout << "minimum cost spanning tree edges: \n" ;
    for (int i {0}; i < V - 1; i++) {
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

// set operations include union and find
void unionOp(int u,int v,int s[]) {
    if (s[u] < s[v]) {
        s[u] += s[v];
        s[v] = u;
    }
    else {
        s[v] += s[u];
        s[u] = v;
    }
}

int findOp(int u,int s[]) {
    int x = u;
    int v = 0;

    while (s[x] > 0) {
        x = s[x];
    }

    while (u != x) {
        v = s[u];
        s[u] = x;
        u = v;
    }

    return x;
}

void start(int A[3][9]) {
    // solution array
    int T[2][V - 1];
    // track edges that are included in solution
    int track[E] {0};
    // array for finding cycle
    int set[V + 1] = {-1,-1,-1,-1,-1,-1,-1,-1};

    int i {0};
    while (i < V - 1) {
        int min = I;
        int u {0};
        int v {0};
        int k {0};

        // find minimum cost edge
        for (int j {0}; j < E; j++) {
            if (track[j] == 0 && A[2][j] < min) {
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }

        // check if selected minimum cost edge (u,v) is forming a cycle or not
        if (findOp(u,set) != findOp(v,set)) {
            T[0][i] = u;
            T[1][i] = v;

            // perform union
            unionOp(findOp(u,set),findOp(v,set),set);
            i++;
        }

        track[k] = 1;
    }

    printMinCostSpaningTree(T,A);
}

int main() {
    cout << "**** kruskal minimum cost spanning tree ****" << endl;
    int edges[3][9] =
        {{1,1,2,2,3,4,4,5,5},
        {2,6,3,7,4,5,7,6,7},
        {25,5,12,10,8,16,14,20,18}};

    start(edges);

    return 0;
}
