#include<bits/stdc++.h>
using namespace std ;

int main() {
	int m ;
	int n ;
	
	cout << "Enter the Value of m :- " ;
	cin >> m;
	
	cout << "Enter the Value of n :- " ;
	cin >> n;
	
	int dimension = min(m,n) ;
	
	int array[dimension + 1];
	array[0] = 0 ;
	
	for(int i = 1 ; i <= dimension ; i++) {
		array[i] = i * i ;
	}
	
	int no = 1 ;
	int area = m * n ;
	area -= (dimension * dimension)
	
	for(int i = dimension - 1 ; i >= 1 ; i--) {
		if(array[i] >= area) {
			no += area % array[i] ;
			
		}
	}
	
	return 0;
	
}