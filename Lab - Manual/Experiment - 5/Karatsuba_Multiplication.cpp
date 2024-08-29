#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int Get_Size(long long num) {
    return num == 0 ? 1 : static_cast<int>(log10(num)) + 1;
}

long long int Karatsuba(long long num1, long long num2) {

    if (num1 < 10 || num2 < 10) {
        return num1 * num2;
    }

    int length = max(Get_Size(num1), Get_Size(num2));
    int half = length / 2 + length % 2;

    long long powerOf10 = static_cast<long long>(pow(10, half));
    long long powerOf102x = powerOf10 * powerOf10;


    long long a = num1 / powerOf10;
    long long b = num1 % powerOf10;
    long long c = num2 / powerOf10;
    long long d = num2 % powerOf10;

    long long ac = Karatsuba(a, c);
    long long bd = Karatsuba(b, d);
    long long ab_cd = Karatsuba(a + b, c + d);
    long long int ans = ac * powerOf102x + (ab_cd - ac - bd) * powerOf10 + bd;

    return ans;
}

int main() {
    long long x = 123456789;
    long long y = 678901234;
    long long int ans = Karatsuba(x, y);
    cout << ans << endl; // Expected result is 838102050

    return 0;
}
