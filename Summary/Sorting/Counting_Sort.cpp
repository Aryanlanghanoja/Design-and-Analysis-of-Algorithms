#include<bits/stdc++.h>
using namespace std;

string Counting_Sort(string str) {
    vector<int> Count_Array(256, 0);

    for (char ch : str) {
        Count_Array[(int)ch]++;
    }

    string sorted_string = "";

    for (int i = 0; i < 256; i++) {
        sorted_string += string(Count_Array[i], (char)i);
    }

    return sorted_string;
}

int main() {
    string str = "abcednfkjfAKODPEFIWEJDLdokwidfjeiojfwclkpowekfWOIREOWPSLDKJFOE";
    string result = Counting_Sort(str);
    cout << result << endl;

    return 0;
}
