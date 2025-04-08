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

void Merge(vector<int> &Array, vector<int> &left, vector<int> &right, int start)
{
    int idx = start; // Start merging from the correct position
    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            Array[idx++] = left[i++];
        }
        else
        {
            Array[idx++] = right[j++];
        }
    }

    while (i < left.size())
    {
        Array[idx++] = left[i++];
    }

    while (j < right.size())
    {
        Array[idx++] = right[j++];
    }
}

void Merge_Sort(vector<int> &Array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively divide the array into two halves
        Merge_Sort(Array, left, mid);
        Merge_Sort(Array, mid + 1, right);

        // Create temporary subarrays for merging
        vector<int> leftArray(Array.begin() + left, Array.begin() + (mid + 1));
        vector<int> rightArray(Array.begin() + (mid + 1), Array.begin() + (right + 1));

        // Merge the sorted subarrays back into the main array
        Merge(Array, leftArray, rightArray, left);
    }
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};
    int size = Array.size();

    cout << "Array Before Sorting :- ";
    Print_Array(Array);

    Merge_Sort(Array, 0, size - 1);

    cout << "Array After Sorting :- ";
    Print_Array(Array);

    return 0;
}
