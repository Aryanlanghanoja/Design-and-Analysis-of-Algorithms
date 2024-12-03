#include <iostream>
#define MAX 11 // Maximum number of vertices

using namespace std;

// Function to perform DFS traversal
void dfs(int graph[MAX][MAX], int current, bool visited[MAX], int parent[MAX], int n) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < n; ++i) {
        if (graph[current][i] && !visited[i]) {
            parent[i] = current; // Record the tree edge
            dfs(graph, i, visited, parent, n);
        }
    }
}

int main() {
    int graph[MAX][MAX] = { 0 };
    int n, edges;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v for each edge):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    bool visited[MAX] = { false };
    int parent[MAX];
    for (int i = 0; i < MAX; ++i) parent[i] = -1;

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(graph, start, visited, parent, n);
    cout << endl;

    // Print the DFS tree
    cout << "DFS Tree Edges:" << endl;
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " -> " << i << endl;
        }
    }

    return 0;
}

