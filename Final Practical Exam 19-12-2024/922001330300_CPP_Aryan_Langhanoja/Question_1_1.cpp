#include <bits/stdc++.h>
using namespace std;

int main()
{
	string input_word;

	cout << "Enter  Your String :- ";
	cin >> input_word;

	vector<string> valid_words = {"apple", "application", "grape", "pineapple", "banana"};

	int max_correct = 0;
	int correct_idx = -1;
	int i = 0;

	while (i < valid_words.size())
	{
		if (input_word.size() != valid_words[i].size())
		{
			i++;
			continue;
		}

		int current_correct = 0;

		for (int j = 0; j < input_word.size(); j++)
		{
			if (input_word[j] == valid_words[i][j])
			{
				current_correct++;
			}
		}

		if (current_correct > max_correct)
		{
			max_correct = current_correct;
			correct_idx = i;
		}

		i++;
	}

	if (correct_idx != -1)
	{
		cout << "Correct word is " << valid_words[correct_idx] << endl;
	}

	else
	{
		cout << "No Closest Word Found" << endl;
	}
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// // Function to calculate the Levenshtein distance
// int levenshteinDistance(const string &s1, const string &s2)
// {
// 	int len1 = s1.size();
// 	int len2 = s2.size();
// 	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

// 	for (int i = 0; i <= len1; i++)
// 	{
// 		for (int j = 0; j <= len2; j++)
// 		{
// 			if (i == 0)
// 			{
// 				dp[i][j] = j; // If s1 is empty
// 			}
// 			else if (j == 0)
// 			{
// 				dp[i][j] = i; // If s2 is empty
// 			}
// 			else if (s1[i - 1] == s2[j - 1])
// 			{
// 				dp[i][j] = dp[i - 1][j - 1]; // No operation needed
// 			}
// 			else
// 			{
// 				dp[i][j] = 1 + min({
// 								   dp[i - 1][j],	// Deletion
// 								   dp[i][j - 1],	// Insertion
// 								   dp[i - 1][j - 1] // Substitution
// 							   });
// 			}
// 		}
// 	}
// 	return dp[len1][len2];
// }

// int main()
// {
// 	string input_word;

// 	cout << "Enter Your String: ";
// 	cin >> input_word;

// 	vector<string> valid_words = {"apple", "application", "grape", "pineapple", "banana"};

// 	int min_distance = INT_MAX;
// 	string closest_word;

// 	for (const string &word : valid_words)
// 	{
// 		int distance = levenshteinDistance(input_word, word);
// 		if (distance < min_distance)
// 		{
// 			min_distance = distance;
// 			closest_word = word;
// 		}
// 	}

// 	if (min_distance != INT_MAX)
// 	{
// 		cout << "Did you mean: " << closest_word << "?" << endl;
// 	}
// 	else
// 	{
// 		cout << "No Closest Word Found" << endl;
// 	}

// 	return 0;
// }