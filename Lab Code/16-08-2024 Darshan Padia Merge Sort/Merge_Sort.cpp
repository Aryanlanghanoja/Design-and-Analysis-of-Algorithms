#include<iostream>
#include<vector>
using namespace std;

void Print_Array(vector<int> Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }

    cout << endl;
}


void Merge(vector<int>& Array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> A1(n1);
    vector<int> A2(n2);

    for (int i = 0; i < n1; i++) {
        A1[i] = Array[left + i];
    }

    for (int j = 0; j < n2;j++) {
        A2[j] = Array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (A1[i] <= A2[j]) {
            Array[k] = A1[i];
            i++;
        }
        else {
            Array[k] = A2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        Array[k] = A1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        Array[k] = A2[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& Array, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        MergeSort(Array, left, mid);
        MergeSort(Array, mid + 1, right);

        Merge(Array, left, mid, right);
    }
}

int main() {
    vector<int> Array = { 26,36,16,12,14,56,34,2,1,4 };
    cout << "Original Array: ";
    Print_Array(Array);
    MergeSort(Array, 0, Array.size() - 1);
    cout << "Sorted Array: ";
    Print_Array(Array);
    return 0;
}