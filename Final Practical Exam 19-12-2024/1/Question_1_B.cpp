// #include <bits/stdc++.h>
// using namespace std;

// vector<string> Split_String(string &submitted_doc)
// {
//     vector<string> input_string;

//     string s = "";
//     for (char c : submitted_doc)
//     {

//         if (c == ',' || c == '.')
//         {
//             continue;
//         }

//         if (c == ' ')
//         {
//             input_string.push_back(s);
//             s = "";
//         }

//         else
//         {
//             s = s + c;
//         }
//     }

//     return input_string;
// }

// int main()
// {
//     string submitted_doc = "In this Paper, We propose a new algorithm for sorting.";
//     string reference_doc = "This Paper introduces a different sorting Algorithm";

//     vector<string> input_string = Split_String(submitted_doc);
//     vector<string> reference_string = Split_String(reference_doc);

//     int n = input_string.size();
//     int m = reference_string.size();

//     int lcs[n + 1][m + 1];

//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             if (i == 0 || j == 0)
//                 lcs[i][j] = 0;
//             else if (input_string[i - 1] == reference_string[j - 1])
//                 lcs[i][j] = lcs[i - 1][j - 1] + 1;
//             else
//                 lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << lcs[i][j] << " ";
//         }
//         cout << endl;
//     }

//     bool found = lcs[n][m] >= 4;

//     cout << "Found: " << (found ? "Yes" : "No") << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<string> Split_String(string &submitted_doc)
{
    vector<string> input_string;

    string s = "";
    for (char c : submitted_doc)
    {

        if (c == ',' || c == '.')
        {
            continue;
        }

        if (c == ' ')
        {
            input_string.push_back(s);
            s = "";
        }

        else
        {
            s = s + c;
        }
    }

    return input_string;
}

void printLCS(vector<string> &input_string, vector<string> &reference_string, vector<vector<int>> &lcs)
{
    int i = input_string.size();
    int j = reference_string.size();
    vector<string> lcs_result;

    // Trace back the LCS
    while (i > 0 && j > 0)
    {
        if (input_string[i - 1] == reference_string[j - 1])
        {
            lcs_result.push_back(input_string[i - 1]);
            i--;
            j--;
        }
        else if (lcs[i - 1][j] >= lcs[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Print the LCS
    reverse(lcs_result.begin(), lcs_result.end());
    for (const string &word : lcs_result)
    {
        cout << word << " ";
    }
    cout << endl;
}

int main()
{
    string submitted_doc = "In this Paper, We propose a new algorithm for sorting.";
    string reference_doc = "This Paper introduces a new sorting algorithm";

    vector<string> input_string = Split_String(submitted_doc);
    vector<string> reference_string = Split_String(reference_doc);

    int n = input_string.size();
    int m = reference_string.size();

    vector<vector<int>> lcs(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (input_string[i - 1] == reference_string[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    // Printing the LCS
    printLCS(input_string, reference_string, lcs);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }

    bool found = lcs[n][m] >= 4;

    cout << "Found: " << (found ? "Yes" : "No") << endl;

    return 0;
}
