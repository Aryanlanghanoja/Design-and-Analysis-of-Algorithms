#include <bits/stdc++.h>
using namespace std;

const int PRIME = 101;
const int MOD = 1e9 + 7;

long long calculateHash(const string &str, int len)
{
    long long hash = 0;
    long long power = 1; // PRIME^0
    for (int i = 0; i < len; ++i)
    {
        hash = (hash + str[i] * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return hash;
}

long long recalculateHash(const string &text, int oldIndex, int newIndex, long long oldHash, int patternLen, long long primePower)
{
    oldHash = (oldHash - text[oldIndex] + MOD) % MOD;
    oldHash = (oldHash / PRIME) % MOD;
    oldHash = (oldHash + text[newIndex] * primePower) % MOD;
    return oldHash;
}

vector<int> Rabin_Karp(const string &text, const string &pattern)
{
    vector<int> result;
    int textLen = text.size();
    int patternLen = pattern.size();

    if (patternLen > textLen)
    {
        return result;
    }

    long long patternHash = calculateHash(pattern, patternLen);
    long long textHash = calculateHash(text, patternLen);

    long long primePower = 1;
    for (int i = 1; i < patternLen; ++i)
    {
        primePower = (primePower * PRIME) % MOD;
    }

    for (int i = 0; i <= textLen - patternLen; ++i)
    {

        if (textHash == patternHash && text.substr(i, patternLen) == pattern)
        {
            result.push_back(i);
        }

        if (i < textLen - patternLen)
        {
            textHash = recalculateHash(text, i, i + patternLen, textHash, patternLen, primePower);
        }
    }

    return result;
}

int main()
{
    string Reference_string = "ATGC";
    string Input_String = "";
    string pattern = "AGC";
    srand(time(0));

    for (int i = 0; i < 25; i++)
    {
        Input_String += Reference_string[rand() % 4];
    }

    cout << "Random String: " << Input_String << endl;
    cout << "Pattern: " << pattern << endl;

    vector<int> occurrences = Rabin_Karp(Input_String, pattern);

    if (occurrences.size() == 0)
    {
        cout << "No occurrences found for the pattern." << endl;
    }

    else
    {
        cout << "Number of occurrences: " << occurrences.size() << endl;

        cout << "Occurrences Founded At Indices :- ";

        for (int ocr : occurrences)
        {
            cout << ocr << " ";
        }

        cout << endl;
    }

    return 0;
}
