#include <bits/stdc++.h>
using namespace std;

long long Expotential(long base, long power) {
    if (power == 0) {
        return 1;
    }

    if (base == 0) {
        return 0;
    }
    
    if (power < 0) {
        return  1 / Expotential(base, power * -1);
    }

    if (power == 1) {
        return base;
    }

    long long Half_Power = Expotential(base, power / 2);

    if (power % 2 == 0) {
        return Half_Power * Half_Power ;
    }

    else {
        return base * Half_Power * Half_Power ;
    }
}

int main() {

    long base;
    long power;

    cout << "Enter the Base of the Expotentail :- ";
    cin >> base;

    cout << "Enter the Power of the Expotential :- ";
    cin >> power;

    long long result = Expotential(base, power);

    cout << "The " << base << " raised to " << power << " is " << result << " ." << endl;
    return 0;
}