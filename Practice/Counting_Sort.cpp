#include <bits/stdc++.h>
using namespace std;

string Counting_Sort(string &str)
{
    int n = str.size();

    vector<int> Count_Array(256, 0);

    for (char &ch : str)
    {
        Count_Array[ch]++;
    }

    int idx = 0;

    string result = "";

    for (int i = 0; i < 256; i++)
    {
        while (Count_Array[i]--)
        {
            result += i;
        }
    }

    return result;
}

int main()
{
    string input = "abcednfkjfAKODPEFIWEJDLdokwidfjeiojfwclkpowekfWOIREOWPSLDKJFOE";
    string result = Counting_Sort(input);
    cout << "Original String:- " << input << endl;
    cout << "Sorted String:- " << result << endl;
    return 0;
}