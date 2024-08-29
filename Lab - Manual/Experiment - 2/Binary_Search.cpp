#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Binary_Search(vector<int> Array, int left, int right, int key) {

    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (key == Array[mid]) {
            return mid;
        }

        if (key < Array[mid]) {
            return Binary_Search(Array, left, mid - 1, key);
        }

        else {
            return Binary_Search(Array, mid + 1, right, key);
        }
    }
}

void Print_Array(vector<int> Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void Input_Array(vector<int>& Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << "Enter Element at index " << i << " : ";
        cin >> Array[i];
    }
}

int main() {
    int size;
    int key;

    while (true) {
        cout << "Enter The Size of the Array :- " << endl;
        cin >> size;

        if (size >= 1) {
            break;
        }

        cout << "Invalid Size. Size must be a Positive Integer." << endl;
    }

    vector<int> Array(size, 0);
    cout << "Enter The Element for the Array:- " << endl;
    Input_Array(Array);
    sort(Array.begin(), Array.end());
    cout << "Your Input Array Is :- " << endl;
    Print_Array(Array);

    cout << "Enter the Key to Search In Array :- ";
    cin >> key;

    int ans = Binary_Search(Array, 0, size, key);

    if (ans != -1) {
        cout << key << " Found at Index - " << ans << " of Array." << endl;
    }

    else {
        cout << "Key is not exists in Array.";
    }
    return 0;
}