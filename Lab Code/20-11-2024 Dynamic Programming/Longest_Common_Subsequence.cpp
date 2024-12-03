#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Longest_Common_Subsequence(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcsString;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsString = X[i - 1] + lcsString;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcsString;
}

int main() {
    // string X = "AGGTAB";
    // string Y = "GXTXAYB";

    string X, Y;

    cout << "Enter The First String :- ";
    cin >> X;

    cout << "Enter The Second String :- ";
    cin >> Y;

    string result = Longest_Common_Subsequence(X, Y);
    cout << "Length of LCS is " << result.length() << endl;
    cout << "LCS is: " << result << endl;

    return 0;
}
