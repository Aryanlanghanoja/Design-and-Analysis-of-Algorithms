#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF 99999

void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

void floydWarshall(int dist[][V])
{

    int i, j, k;

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {

                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

// Driver's code
int main()
{
    int graph[V][V] = {{0, 3, INF, 7, 8},
                       {INF, 0, 1, 4, INF},
                       {INF, INF, 0, INF, INF},
                       {INF, INF, 2, 0, INF},
                       {INF, INF, INF, 3, 0}};

    floydWarshall(graph);
    return 0;
}
