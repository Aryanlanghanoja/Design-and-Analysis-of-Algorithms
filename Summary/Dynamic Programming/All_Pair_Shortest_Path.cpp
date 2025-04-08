#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void allPairsShortestPathDP(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, INF)));

    // Initialize the base case: no intermediate nodes
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j][0] = (i == j) ? 0 : graph[i][j]; // distance 0 if same node, else edge weight
        }
    }

    // Fill dp[i][j][k] considering up to k intermediate nodes
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][k] = dp[i][j][k - 1]; // Without using the k-th node
                for (int x = 0; x < n; ++x) {
                    if (dp[i][x][k - 1] != INF && dp[x][j][k - 1] != INF) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][x][k - 1] + dp[x][j][k - 1]);
                    }
                }
            }
        }
    }

    // Print the result using the full range of intermediate nodes
    cout << "Shortest distances between all pairs of nodes:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j][n] == INF) {
                cout << "INF ";
            }
            else {
                cout << dp[i][j][n] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use " << INF << " for no direct edge):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == INF && i != j) {
                graph[i][j] = INF; // Assign INF for no edge
            }
        }
    }

    allPairsShortestPathDP(graph);

    return 0;
}
