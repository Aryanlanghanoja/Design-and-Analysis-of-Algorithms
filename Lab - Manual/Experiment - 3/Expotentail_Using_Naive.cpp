#include <bits/stdc++.h>
using namespace std;

long long Expotential(long base, long power) {
    if (power == 0) {
        return 1;
    }

    if (power == 1) {
        return base;
    }

    return base * Expotential(base, power - 1);
}

int main() {

    long base;
    long power;

    cout << "Enter the Base of the Ecpotentail :- ";
    cin >> base;

    cout << "Enter the Power of the Expotential :- ";
    cin >> power;

    long long result = Expotential(base, power);

    cout << "The " << base << " raised to " << power << " is " << result << " ." << endl;
    return 0;
}