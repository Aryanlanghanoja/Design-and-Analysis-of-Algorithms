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

void Bubble_Sort(vector<int> &Array)
{
    int n = Array.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                Swap(Array[j], Array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};

    cout << "Array Before Sorting :- ";
    Print_Array(Array);

    Bubble_Sort(Array);

    cout << "Array After Sorting :- ";
    Print_Array(Array);

    return 0;
}
