#include <bits/stdc++.h>
using namespace std;

void Prime_Factorization(long long n)
{
    for (long long i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            cout << i;
            n /= i;
            
            if(n != 1) {
            	cout << " X ";
			}
        }
    }
    
    if (n > 1)
    {
        cout << n;
    }
}

int main()
{
    long long number;

    cout << "Enter A Number :- ";
    cin >> number;

    cout << "Prime Factorization of " << number << " is : ";
    Prime_Factorization(number);

    return 0;
}
