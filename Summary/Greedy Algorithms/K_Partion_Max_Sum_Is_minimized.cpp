#include <bits/stdc++.h>
using namespace std;

int minimizeLargestSum(vector<int>& nums, int k) {

    sort(nums.rbegin(), nums.rend());

    vector<int> subsetSums(k, 0);

    for (int num : nums) {
        int minIndex = 0;
        for (int i = 1; i < k; i++) {
            if (subsetSums[i] < subsetSums[minIndex]) {
                minIndex = i;
            }
        }
        subsetSums[minIndex] += num;
    }


    return *max_element(subsetSums.begin(), subsetSums.end());
}


int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int result = minimizeLargestSum(nums, k);
    cout << "The minimized largest sum is: " << result << endl;

    return 0;
}
