#include <bits/stdc++.h>
using namespace std;

int main()
{
    int denomination;
    cout << "Enter the Number of Denominations :- ";
    cin >> denomination;

    vector<pair<int, int>> storage;

    for (int i = 0; i < denomination; i++)
    {

        cout << "Enter The Details for (" << i + 1 << ") Coins :-" << endl;

        int val = 0;
        int quantity = 0;

        cout << "Enter the Value of Coin :- ";
        cin >> val;

        cout << "Enter the Quantity of Coins :- ";
        cin >> quantity;

        storage.push_back({val, quantity});
    }

    sort(storage.begin(), storage.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first > b.first; });

    int amount;
    cout << "Enter the Amount :- ";
    cin >> amount;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < denomination; i++)
    {
        for (int j = storage[i].first; j <= amount; j++)
        {
            if (dp[j - storage[i].first] != INT_MAX && dp[j - storage[i].first] + 1 < dp[j])
            {
                dp[j] = dp[j - storage[i].first] + 1;
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        cout << "Minimum Number of Coins Required is Not Possible" << endl;
    }
    else
    {
        cout << "Minimum Number of Coins Required is " << dp[amount] << endl;
    }
    return 0;
}
