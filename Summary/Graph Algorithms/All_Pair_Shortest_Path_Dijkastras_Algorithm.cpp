#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path from a source to all vertices using Dijkstra's algorithm
void dijkstra(int src, const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &parent)
{
    int V = graph.size();
    dist.assign(V, INT_MAX);
    parent.assign(V, -1);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// Function to reconstruct and print the path from src to dest
void printPath(int src, int dest, const vector<int> &parent)
{
    if (dest == -1)
    {
        cout << "No path";
        return;
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    for (int v : path)
        cout << v << " ";
}

// All-pairs shortest path using Dijkstra's algorithm
void allPairsShortestPath(const vector<vector<pair<int, int>>> &graph)
{
    int V = graph.size();
    for (int i = 0; i < V; i++)
    {
        vector<int> dist, parent;
        dijkstra(i, graph, dist, parent);

        cout << "Shortest distances from vertex " << i << ":\n";
        for (int j = 0; j < V; j++)
        {
            if (dist[j] == INT_MAX)
                cout << "To " << j << ": INF\n";
            else
                cout << "To " << j << ": " << dist[j] << "\n";
        }

        cout << "\nPaths from vertex " << i << ":\n";
        for (int j = 0; j < V; j++)
        {
            cout << "Path to " << j << ": ";
            if (dist[j] == INT_MAX)
                cout << "No path\n";
            else
                printPath(i, j, parent);
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    // Number of vertices
    int V = 4;

    // Graph represented as an adjacency list
    // Each pair is {destination, weight}
    vector<vector<pair<int, int>>> graph(V);
    graph[0].push_back({1, 3});
    graph[0].push_back({3, 5});
    graph[1].push_back({0, 2});
    graph[1].push_back({3, 4});
    graph[2].push_back({1, 1});
    graph[3].push_back({2, 2});

    allPairsShortestPath(graph);

    return 0;
}
