#include<bits/stdc++.h>
using namespace std ;

bool isPalindrome(string &s , int start , int end) {
	string curr(s.begin() + start , s.end() + (end + 1)) ;
	
	int size = end - start + 1;
	
	for(int i = 0 ; i <= size / 2 ; i++) {
		if(s[i] != s[size - i - 1]) {
			return false ;
		}
	}
	
	return true;
}

int Total_Palindrome_Subsequence(string &s) {
	int total = 0 ;
	
	for(int i = 0 ; i < s.size() ; i++) {
		for(int j = i + 1 ; j < s.size()  ; j++) {
			bool ans = isPalindrome(s, i , j) ;
			total += ans ; 
		}
	}
	
	return total ;
}

int main() {
	string s ;
	
	cout << "Enter the String :- " ;
	cin >> s ;
	
	int total_Palindrome = Total_Palindrome_Subsequence(s) ;
	
	cout <<"The Total Palindrome Subsequences are " << total_Palindrome << endl;
	
	return 0;
}