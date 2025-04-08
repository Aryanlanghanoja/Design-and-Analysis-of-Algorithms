#include <iostream>
#include <vector>
using namespace std;

void Swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Print_Array(vector<int> Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int Partition(int left, int right, vector<int> &Array)
{
    int pivot = Array[right];
    // int high = right;

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
void Quick_Sort(vector<int> &Array, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(low, high, Array);
        Quick_Sort(Array, low, pivot - 1);
        Quick_Sort(Array, pivot + 1, high);
    }
}

int main()
{
    vector<int> Array = {12, 45, 57, 78, 89, 62, 7, 49, 21, 23};
    int size = Array.size();

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Quick_Sort(Array, 0, size - 1);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}