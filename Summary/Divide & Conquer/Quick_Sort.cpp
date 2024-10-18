#include <bits/stdc++.h>
using namespace std;

void Swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void Print_Array(vector<int> Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int Partion(vector<int>& Array, int left, int right) {
    int pivot = Array[left];

    while (true) {
        while (left < right && Array[left] < pivot) {
            left++;
        }

        while (left < right && Array[right] > pivot) {
            right--;
        }

        if (left >= right) {
            break;
        }

        Swap(Array[left], Array[right]);
    }

    Swap(Array[right], pivot);

    return right;
}

void Quick_Sort(vector<int>& Array, int left, int right) {
    if (left < right) {
        int Pivot_Index = Partion(Array, left, right);
        Quick_Sort(Array, left, Pivot_Index - 1);
        Quick_Sort(Array, Pivot_Index + 1, right);
    }
}

int main() {
    vector<int> Array = { 12, 45, 57, 78, 89, 62, 7, 49, 21, 23 };
    int size = Array.size();

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Quick_Sort(Array, 0, size - 1);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}