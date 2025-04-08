#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i >= x && dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i >= y && dp[i - y] != -1)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i >= z && dp[i - z] != -1)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    return dp[n] != -1 ? dp[n] : 0;
}

int main()
{
    int n, x, y, z;

    cout << "Enter the length of the line segment (n): ";
    cin >> n;
    cout << "Enter the first cut length (x): ";
    cin >> x;
    cout << "Enter the second cut length (y): ";
    cin >> y;
    cout << "Enter the third cut length (z): ";
    cin >> z;

    int result = maxSegments(n, x, y, z);
    cout << "The maximum number of segments that can be cut from length " << n
         << " using lengths " << x << ", " << y << ", and " << z << " is: " << result << endl;

    return 0;
}