#include <bits/stdc++.h>
using namespace std;

int main()
{
	string order;
	string s;

	cout << "Enter the Order String: ";
	cin >> order;

	cout << "Enter the Input String S: ";
	cin >> s;

	unordered_map<char, int> priority_table;

	int priority = order.size();
	for (char c : order)
	{
		priority_table[c] = priority;
		priority--;
	}

	sort(s.begin(), s.end(), [&priority_table](char a, char b)
		 { return priority_table[a] > priority_table[b]; });

	cout << "Output is: " << s << endl;

	return 0;
}