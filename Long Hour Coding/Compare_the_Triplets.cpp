#include <bits/stdc++.h>
using namespace std;

void compareTriplets(int a[3] ,int b[3] , int result[2]) {
    int alice = 0;
    int bob = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice++;
        }

        else if (a[i] < b[i]) {
            bob++;
        }
    }

    result[0] = alice;
    result[1] = bob;
}

int main() { 

    int a[3] = {};
    int b[3] = {};

    for (int i = 0; i < 3; i++) {
        cout << "Enter a[" << i << "] :-";
        cin >> a[i];

        cout << "Enter b[" << i << "] :-";
        cin >> b[i];
    }

    int result[2];

    compareTriplets(a, b, result);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}