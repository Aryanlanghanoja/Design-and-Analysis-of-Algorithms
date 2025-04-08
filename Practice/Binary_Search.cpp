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

int Binary_Search(vector<int> &Array, int key)
{
    int left = 0;
    int right = Array.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (Array[mid] == key)
        {
            return mid;
        }

        else if (Array[mid] < key)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};
    int key;

    sort(Array.begin(), Array.end());

    cout << "Array :- ";
    Print_Array(Array);

    cout << "Enter the Key to Search in the Array :- ";
    cin >> key;

    int index = Binary_Search(Array, key);

    if (index != -1)
    {
        cout << "Key Found at Index " << index << endl;
    }

    else
    {
        cout << "Key Not Found in the Array" << endl;
    }

    return 0;
}