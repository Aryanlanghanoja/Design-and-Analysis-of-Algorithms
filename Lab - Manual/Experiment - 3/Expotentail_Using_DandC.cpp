#include <bits/stdc++.h>
using namespace std;

long long Expotential(long base, long power)
{
    if (power == 0)
    {
        return 1;
    }

    else if (power % 2 == 0)
    {
        return Expotential(base, power / 2) * Expotential(base, power / 2);
    }

    else
    {
        return base * Expotential(base, power / 2) * Expotential(base, power / 2);
    }
}

int main()
{

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