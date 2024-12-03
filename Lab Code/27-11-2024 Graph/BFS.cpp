#include <iostream>
#include <queue>
#define MAX 11 // Maximum number of vertices

using namespace std;

// Function to perform BFS traversal
void bfs(int graph[MAX][MAX], int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    bool visited[MAX] = { false };

    // Tree edges representation
    int parent[MAX];
    for (int i = 0; i < MAX; ++i) parent[i] = -1;

    // Add the start vertex to the queue and mark it as visited
    queue[rear++] = start;
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int current = queue[front++];
        cout << current << " ";

        for (int i = 0; i < n; ++i) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
                parent[i] = current; // Record the tree edge
            }
        }
    }
    cout << endl;

    // Print the BFS tree
    cout << "BFS Tree Edges:" << endl;
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " -> " << i << endl;
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

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    bfs(graph, start, n);

    return 0;
}

