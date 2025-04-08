#include <iostream>
#include <vector>
using namespace std;

void Print_Array(vector<int> Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        cout << Array[i] << " ";
    }

    cout << endl;
}

int Find_Max(vector<int> Array)
{
    int max_num = Array[0];
    for (int i = 1; i < Array.size(); i++)
    {
        if (Array[i] > max_num)
        {
            max_num = Array[i];
        }
    }
    return max_num;
}

void Counting_Sort(vector<int> &Array)
{
    int max_num = Find_Max(Array);
    vector<int> count(max_num + 1, 0);

    for (int i = 0; i < Array.size(); i++)
    {
        count[Array[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_num; i++)
    {
        while (count[i] > 0)
        {
            Array[index++] = i;
            count[i]--;
        }
    }

    return;
}

int main()
{
    vector<int> Array = {12, 45, 57, 78, 89, 62, 7, 49, 21, 23};

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Counting_Sort(Array);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}