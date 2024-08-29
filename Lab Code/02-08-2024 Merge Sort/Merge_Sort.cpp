#include <iostream>
#include <vector>
using namespace std;

void Print_Array(const vector<int>& Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void Merge(vector<int>& Array, int low, int mid, int high) {
    int lower_bound = mid - low + 1;
    int upper_bound = high - mid;

    vector<int> Lower(lower_bound);
    vector<int> Upper(upper_bound);

    for (int i = 0; i < lower_bound; i++) {
        Lower[i] = Array[low + i];
    }

    for (int i = 0; i < upper_bound; i++) {
        Upper[i] = Array[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < lower_bound && j < upper_bound) {
        if (Lower[i] <= Upper[j]) {
            Array[k] = Lower[i];
            i++;
        }
        else {
            Array[k] = Upper[j];
            j++;
        }
        k++;
    }

    while (i < lower_bound) {
        Array[k] = Lower[i];
        i++;
        k++;
    }

    while (j < upper_bound) {
        Array[k] = Upper[j];
        j++;
        k++;
    }
}

void Merge_Sort(vector<int>& Array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        Merge_Sort(Array, left, mid);
        Merge_Sort(Array, mid + 1, right);

        Merge(Array, left, mid, right);
    }
}

int main() {
    vector<int> Array = { 12, 45, 57, 78, 89, 62, 7, 49, 21, 23 };
    int size = Array.size();

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Merge_Sort(Array, 0, size - 1);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}
