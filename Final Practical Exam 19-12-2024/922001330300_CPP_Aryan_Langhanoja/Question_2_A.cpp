#include<bits/stdc++.h>
using namespace std ;

string decimal_to_binary(int num) {
	string ans = "" ;
	
	while(num != 0) {
		char curr = (num % 2 == 0 ? '0' : '1') ;
		ans += curr ;
		
		num /= 2 ;
	}
	
	reverse(ans.begin() , ans.end()) ;
	
	return ans;
}

int main() {
	int a;
	int b ;
	
	cout << "Enter Number - 1 :- " ;
	cin >> a ;
	
	cout << "Enter Number - 2 :- " ;
	cin >> b ;
	
	string n1 = decimal_to_binary(a) ;
	string n2 = decimal_to_binary(b) ;
	
	for(int i = 1 ; i <= 8 - n1.size(); i++) {
		n1 = "0" + n1 ;
	}

	for(int i = 1 ; i <= 8 - n2.size(); i++) {
		n2 = "0" + n2 ;
	}
	
	int flip = 0 ;
	int no_of_bits = n1.size();
	
	for(int i = 0 ; i < no_of_bits ; i++) {
		if(n1[i] != n2[i]) {
			flip++;
		}
	}
	
	cout << "Flips Required are :- " << flip << endl;
}