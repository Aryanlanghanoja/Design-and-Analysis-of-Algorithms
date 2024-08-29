#include<iostream>
#include<cmath>
using namespace std;

int Get_Size(long long num) {
    return num == 0 ? 1 : (int)log10(num) + 1;
}

long long int Karatsuba_multiplication(long long x, long long y) {

    if (x < 10 || y < 10) {
        return x * y;
    }


    int size = max(Get_Size(x), Get_Size(y));
    int nby2 = size / 2 + size % 2;
    long long pow_10 = (long)pow(10, nby2);
    long long power_10_size = pow_10 * pow_10;
    long long a = x / pow_10;
    long long b = x % pow_10;
    long long c = y / pow_10;
    long long d = y % pow_10;

    long long ac = Karatsuba_multiplication(a, c);
    long long bd = Karatsuba_multiplication(b, d);
    long long ab_cd = Karatsuba_multiplication(a + b, c + d);

    long long int ans = ac * power_10_size + (ab_cd - ac - bd) * pow_10 + bd;

    return ans;

}

int main() {
    long long x = 123456;
    long long y = 567890;

    long long int ans = Karatsuba_multiplication(x, y);
    cout << ans;
    return 0;
}