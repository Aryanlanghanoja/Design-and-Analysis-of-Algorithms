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

void Insertion_Sort(vector<int> &Array)
{
    int n = Array.size();

    for (int i = 0; i < n; i++)
    {
        int key = Array[i];
        int j = i - 1;

        while (j >= 0 && Array[j] > key)
        {
            Array[j + 1] = Array[j];
            j--;
        }

        Array[j + 1] = key;
    }
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};

    cout << "Array Before Sorting :- ";
    Print_Array(Array);

    Insertion_Sort(Array);

    cout << "Array After Sorting :- ";
    Print_Array(Array);

    return 0;
}