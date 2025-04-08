#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constants
const int PRIME = 101;   // A prime number for hashing
const int MOD = 1e9 + 7; // A large prime for modulo

// Function to calculate the initial hash value
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

// Function to recalculate the hash value for the next window
long long recalculateHash(const string &text, int oldIndex, int newIndex, long long oldHash, int patternLen, long long primePower)
{
    oldHash = (oldHash - text[oldIndex] + MOD) % MOD;        // Remove the old character
    oldHash = (oldHash / PRIME) % MOD;                       // Shift hash to the left
    oldHash = (oldHash + text[newIndex] * primePower) % MOD; // Add the new character
    return oldHash;
}

// Rabin-Karp algorithm to find all occurrences of a pattern in the text
vector<int> rabinKarp(const string &text, const string &pattern)
{
    vector<int> result;
    int textLen = text.size();
    int patternLen = pattern.size();

    if (patternLen > textLen)
    {
        return result; // Pattern cannot be found
    }

    // Calculate the hash for the pattern and the first window of text
    long long patternHash = calculateHash(pattern, patternLen);
    long long textHash = calculateHash(text, patternLen);

    // Precompute PRIME^(patternLen-1) % MOD for sliding the window
    long long primePower = 1;
    for (int i = 1; i < patternLen; ++i)
    {
        primePower = (primePower * PRIME) % MOD;
    }

    // Sliding the window over the text
    for (int i = 0; i <= textLen - patternLen; ++i)
    {
        // If hash values match, compare the actual substrings to avoid false positives
        if (textHash == patternHash && text.substr(i, patternLen) == pattern)
        {
            result.push_back(i); // Match found
        }

        // Recalculate the hash for the next window
        if (i < textLen - patternLen)
        {
            textHash = recalculateHash(text, i, i + patternLen, textHash, patternLen, primePower);
        }
    }

    return result;
}

int main()
{

    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int>
        matches = rabinKarp(text, pattern);

    if (!matches.empty())
    {
        cout << "Pattern found at indices: ";
        for (int index : matches)
        {
            cout << index << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Pattern not found." << endl;
    }

    return 0;
}
