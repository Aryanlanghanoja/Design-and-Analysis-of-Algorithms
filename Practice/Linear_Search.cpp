#include <bits/stdc++.h>
using namespace std;

int Linear_Search(vector<int> &Array, int key)
{
    for (int i = 0; i < Array.size(); i++)
    {
        if (Array[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    vector<int> Array = {97, 211, 459, 405, 130, 484, 112, 184, 764, 299};
    int key;

    cout << "Enter the Key to Search in the Array :- ";
    cin >> key;

    int index = Linear_Search(Array, key);

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