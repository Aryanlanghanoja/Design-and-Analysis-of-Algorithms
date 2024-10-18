#include<bits/stdc++.h>
using namespace std;

void Print_Array(vector<int> Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }

    cout << endl;
}

void Insertion_Sort(vector<int>& Array) {
    for (int i = 1; i < Array.size(); i++) {
        int key = Array[i];
        int j = i - 1;

        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j--;
        }

        Array[j + 1] = key;
    }
}

int main() {
    vector<int> Array = { 12 ,45 , 57 , 78 , 89 , 62 , 7 , 49 , 21 , 23 };

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Insertion_Sort(Array);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}