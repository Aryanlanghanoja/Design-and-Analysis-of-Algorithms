#include <bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Print_Array(vector<int> Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int Partitation(vector<int> &Array, int left, int right)
{
    int pivot = Array[right];

    while (true)
    {
        while (left < right && Array[left] < pivot)
        {
            left++;
        }

        while (left < right && Array[right] > pivot)
        {
            right--;
        }

        if (left >= right)
        {
            break;
        }

        Swap(Array[left], Array[right]);
    }

    Swap(Array[left], pivot);

    return left;
}

void Quick_Sort(vector<int> &Array, int left, int right)
{
    if (left < right)
    {
        int partition_idx = Partitation(Array, left, right);
        Quick_Sort(Array, left, partition_idx - 1);
        Quick_Sort(Array, partition_idx + 1, right);
    }
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};
    int size = Array.size();

    cout << "Array Before Sorting :- ";
    Print_Array(Array);

    Quick_Sort(Array, 0, size - 1);

    cout << "Array After Sorting :- ";
    Print_Array(Array);

    return 0;
}