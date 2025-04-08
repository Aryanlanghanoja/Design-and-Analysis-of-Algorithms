#include <bits/stdc++.h>
using namespace std;

void Print_Array(vector<int> Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Selection_Sort(vector<int> &Array)
{
    int n = Array.size();

    for (int i = 1; i < n; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (Array[j] < Array[min_index])
            {
                min_index = j;
            }
        }

        Swap(Array[min_index], Array[i]);
    }
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};

    cout << "Array Before Sorting :- ";
    Print_Array(Array);

    Selection_Sort(Array);

    cout << "Array After Sorting :- ";
    Print_Array(Array);

    return 0;
}