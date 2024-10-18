#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 0)
        return 1;

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    double half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main() {
    double x;
    int n;

    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    cout << x << "^" << n << " = " << power(x, n) << endl;

    return 0;
}
