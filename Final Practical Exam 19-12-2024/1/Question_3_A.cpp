#include <bits/stdc++.h>
using namespace std;

void findCriticalConnections(vector<vector<int>> &graph, int node)
{
    int min_degree = INT_MAX;
    int src = -1;
    int dest = -1;
    vector<pair<int, int>> criticalConnections;

    for (int i = 0; i < node; i++)
    {
        int curr_degree = 0;

        for (int j = 0; j < node; j++)
        {
            if (graph[i][j] != 9999 && graph[i][j] != 0)
                curr_degree++;
        }

        if (curr_degree == 1)
        {
            for (int j = 0; j < node; j++)
            {
                if (graph[i][j] != 9999 && graph[i][j] != 0)
                {
                    src = i;
                    dest = j;
                    criticalConnections.push_back({src, dest});
                }
            }
        }
    }

    for (auto connection : criticalConnections)
    {
        cout << "The Critical Connection is from " << connection.first << " to " << connection.second << endl;
    }
}

int main()
{

    int node;

    cout << "Enter The Number of Nodes :- ";
    cin >> node;

    vector<vector<int>> graph(node, vector<int>(node, 9999));

    cout << "Enter The Adjacency Matrix :- " << endl;

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << "Enter The Edge from " << i << " to " << j << " (9999 for no edge) :- ";
            cin >> graph[i][j];
        }
    }

    findCriticalConnections(graph, node);

    return 0;
}
