// C++ code to implement the 
// matrix chain multiplication using tabulation
#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int>& arr) {

    int n = arr.size();

    // Create a 2D DP array to store the minimum
    // multiplication costs
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP array.
    // Here, len is the chain length
    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << setw(4) << dp[i][j] << " ";
        }

        cout << endl;
        
    }

    // The minimum cost is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {

    // vector<int> arr = { 5,4,6,2,7 };
    vector<int> arr;
    int n;
    cout << "Enter the Number of Matrix :- ";
    cin >> n;

    for( int i = 0; i < n; i++) {
        int row, column;

        cout << "Enter the Number of Rows and Columns for Matrix " << i + 1 << " :- ";
        cin >> row >> column;

        if (i == 0) {
            arr.push_back(row);
            arr.push_back(column);
        }

        else {
            arr.push_back(column);
        }
    }

    cout << matrixMultiplication(arr);

    return 0;
}