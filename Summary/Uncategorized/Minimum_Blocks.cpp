#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_squares(int m, int n, vector<vector<int>> &memo)
{
    if (m == n)
    {
        return 1;
    }

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }

    int min_count = m * n; // Initialize with a large value

    for (int k = 1; k <= min(m, n); ++k)
    {
        int count1 = 1 + min_squares(m - k, n, memo);
        int count2 = 1 + min_squares(m, n - k, memo);
        min_count = min(min_count, min(count1, count2));
    }

    memo[m][n] = min_count;
    return min_count;
}

int main()
{
    int m, n;
    cout << "Enter the dimensions of the rectangle (m n): ";
    cin >> m >> n;

    if (m <= 0 || n <= 0)
    {
        cout << "Dimensions must be positive." << endl;
        return 1;
    }

    // Initialize memoization table
    vector<vector<int>> memo(max(m, n) + 1, vector<int>(max(m, n) + 1, -1));

    int result = min_squares(m, n, memo);
    cout << "Minimum number of squares: " << result << endl;

    // Example of a larger case (be mindful of computation time)
    // m = 20, n = 15;
    // memo.assign(max(m,n)+1, vector<int>(max(m,n)+1,-1)); //resize memo
    // result = min_squares(m, n, memo);
    // cout << "Minimum number of squares for 20x15: " << result << endl;

    return 0;
}