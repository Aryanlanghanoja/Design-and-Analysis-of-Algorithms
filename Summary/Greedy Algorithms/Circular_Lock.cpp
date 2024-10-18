#include <bits/stdc++.h>
using namespace std;

bool Unlock(int input, int password, int threshold) {
    int rotation = 0;

    while (input > 0) {
        int a = input % 10;
        int b = password % 10;
        int temp = abs(a - b);
        rotation += min(temp, 10 - temp);
        input /= 10;
        password /= 10;
    }

    if (rotation <= threshold) {
        return true;
    }

    else {
        return false;
    }

}

int main() { 

    int input = 4567;
    int password = 1234;
    int threshold = 15;

    if (Unlock(input, password, threshold)) {
        cout << "We Can Unlock the Lock within threshold Rotation." << endl;
    }

    else {
        cout << "We Can't Unlock the Lock within threshold Rotation." << endl;
    }

    return 0;
}