#include<bits/stdc++.h>
using namespace std;

void Print_Array(vector<int> Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }

    cout << endl;
}

void Swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void Bubble_Sort(vector<int>& Array) {
    int size = Array.size();

    for (int i = 0; i < size - 1; i++) {
        bool Swapped = false;

        for (int j = 0; j < size - i - 1; j++) {

            if (Array[j] > Array[j + 1]) {
                Swap(Array[j], Array[j + 1]);
                Swapped = true;
            }
        }

        if (Swapped == false) {
            break;
        }
    }

    return;
}

int main() {
    vector<int> Array = { 12 ,45 , 57 , 78 , 89 , 62 , 7 , 49 , 21 , 23 };

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Bubble_Sort(Array);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}