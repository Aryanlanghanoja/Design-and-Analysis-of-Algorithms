#include<bits/stdc++.h>
using namespace std;

string Time_Conversion(string s) {
    int h = stoi(s.substr(0, 2));
    string minute = s.substr(3, 2);
    string second = s.substr(6, 2);
    string am_pm = s.substr(8, 2);

    if (am_pm == "PM") {
        h += 12;
    }

    string hour;

    int unit = h % 10;
    h = h / 10;
    int decimals = h % 10;

    if (decimals == 0) {
        hour = "0" + to_string(unit);
    }

    else {
        hour = to_string(decimals) + to_string(unit);
    }

    string Time_24 = hour + ":" + minute + ":" + second;

    return Time_24;
}

int main() {

    string s;
    cout << "Enter a time in 12-hour format (HH:MM:SS AM/PM): ";
    cin >> s;

    cout << "Converted Time (24-hour format): ";
    cout << Time_Conversion(s) << endl;

    return 0;
}