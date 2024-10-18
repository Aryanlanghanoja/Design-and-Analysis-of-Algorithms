#include <bits/stdc++.h>
using namespace std;

int Kedans_Algorithmn(vector<int>& nums) {
    int max_sum = INT_MIN;
    int current_sum = 0;

    for (int num : nums) {
        current_sum += num;
        max_sum = max(current_sum, max_sum);

        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return max_sum;
}

int main() { 

    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int max_subarray_sum = Kedans_Algorithmn(nums);
    cout << "Maximum Subarry Sum Is " << max_subarray_sum << endl;
    return 0;
}