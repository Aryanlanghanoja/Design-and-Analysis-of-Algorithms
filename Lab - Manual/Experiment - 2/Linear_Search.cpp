#include<iostream>
#include<vector>
using namespace std;

int Linear_Search(vector<int> Array, int key) {
    for (int i = 0; i < Array.size(); i++) {
        if (Array[i] == key) {
            return i;
        }
    }

    return -1;
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
    cout << "Your Input Array Is :- " << endl;
    Print_Array(Array);

    cout << "Enter the Key to Search In Array :- ";
    cin >> key;

    int ans = Linear_Search(Array, key);
    if (ans != -1) {
        cout << key << " Found at Index - " << ans << " of Array." << endl;
    }

    else {
        cout << "Key is not exists in Array.";
    }
    return 0;
}