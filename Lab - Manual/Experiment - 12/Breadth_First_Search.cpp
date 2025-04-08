#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited);

void bfsDisconnected(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);

    for (int i = 0; i < adj.size(); ++i)
    {
        if (!visited[i])
        {
            bfs(adj, i, visited);
        }
    }
}

void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited)
{
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 6;

    vector<vector<int>> adj(V);
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    cout << "Complete BFS of the graph:" << endl;
    bfsDisconnected(adj);

    return 0;
}