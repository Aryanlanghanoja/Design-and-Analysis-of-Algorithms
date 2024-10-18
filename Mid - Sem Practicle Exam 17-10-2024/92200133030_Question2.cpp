#include <bits/stdc++.h>
using namespace std;

void Merge(vector <pair<int, string>>& Marks, int low, int mid, int high) {

    int lower_bound = mid - low + 1;
    int upper_bound = high - mid;

    vector<pair<int, string>> Left_Array(lower_bound);
    vector<pair<int, string>> Right_Array(upper_bound);

    for (int i = 0; i < lower_bound; i++) {
        Left_Array[i] = Marks[low + i];
    }

    for (int i = 0; i < upper_bound; i++) {
        Right_Array[i] = Marks[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < lower_bound && j < upper_bound) {
        if (Left_Array[i] <= Right_Array[j]) {
            Marks[k] = Left_Array[i];
            i++;
        }

        else {
            Marks[k] = Right_Array[j];
            j++;
        }

        k++;
    }

    while (i < lower_bound) {
        Marks[k] = Left_Array[i];
        i++;
        k++;
    }

    while (j < upper_bound) {
        Marks[k] = Right_Array[j];
        j++;
        k++;
    }
}

void Merge_Sort(vector <pair<int, string>>& Marks, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        Merge_Sort(Marks, left, mid);
        Merge_Sort(Marks, mid + 1, right);
        Merge(Marks, left, mid, right);
    }
}

int main() { 

    vector<pair<int, string>> Marks = { {95, "Alice"}, {85, "Bob"}, {85, "Charlie"}, {89, "David"} };

    int left = 0;
    int right = Marks.size() - 1;
    Merge_Sort(Marks, left, right);

    int min_marks = Marks[0].first;
    vector<string> min_studens;

    for (int i = 0; i < Marks.size(); i++) {
        if (Marks[i].first == min_marks) {
            min_studens.push_back(Marks[i].second);
        }
    }

    int max_marks = Marks.back().first;
    vector<string> max_studens;

    for (int i = Marks.size(); i >= 0 ; i--) {
        if (Marks[i].first == max_marks) {
            max_studens.push_back(Marks[i].second);
        }
    }

    cout << "The Maximum Marks are " << max_marks << endl;
    cout << "The Student Sccored Max_Marks are :- ";

    for (string name : max_studens) {
        cout << name << " , ";
    }

    cout << endl;

    cout << "The Minimum Marks are " << min_marks << endl;
    cout << "The Student Sccored Max_Marks are :- ";

    for (string name : min_studens) {
        cout << name << " , ";
    }

    cout << endl;

    return 0;
}