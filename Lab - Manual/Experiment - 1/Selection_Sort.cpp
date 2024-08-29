#include<iostream>
#include<vector>
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

void Selection_Sort(vector<int>& Array) {

    for(int i = 0; i < Array.size(); i++) {
        int min_index = i;

        for (int j = i + 1; j < Array.size(); j++) {

            if (Array[j] < Array[min_index]) {
                min_index = j;
            }
        }

        Swap(Array[i], Array[min_index]);
    }

    return;
}

int main() {
    vector<int> Array = { 12 ,45 , 57 , 78 , 89 , 62 , 7 , 49 , 21 , 23 };

    cout << "Array Before Sorting :- " << endl;
    Print_Array(Array);

    Selection_Sort(Array);

    cout << "Array After Sorting :- " << endl;
    Print_Array(Array);

    return 0;
}