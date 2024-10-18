#include <bits/stdc++.h>
using namespace std;

int Smallest_Number(int sum, int digit) {

    if (sum == 0) {
        if (digit == 1) {
            return 0;
        }

        else {
            return -1;
        }
    }

    if (sum >= 9 * digit) {
        return -1;
    }

    vector<int> result(digit, 0);
    sum--;

    for (int i = digit-1; i > 0; i--) {
        if (sum > 9) {
            result[i] = 9;
            sum -= 9;
        }

        else {
            result[i] = sum;
            sum = 0;
        }
    }

    result[0] = sum + 1;
    int number = 0;

    for (int i = 0; i < digit; i++) {
        number = number * 10 + result[i];
    }

    return number;

}

int main() { 

    int sum = 9;
    int digit = 2;
    int number = Smallest_Number(sum, digit);

    cout << "The Smallest Number Is :- " << number << endl;

    return 0;
}