#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition_algo(vector<int> &nums, int L, int R)
    {

        int P = nums[L];
        int i = L + 1;
        int j = R;

        while (i <= j)
        {

            if (nums[i] < P && nums[j] > P)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if (nums[i] >= P)
            {
                i++;
            }

            if (nums[j] <= P)
            {
                j--;
            }
        }

        swap(nums[L], nums[j]);
        return j;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        int L = 0;
        int R = n - 1;

        int pivot_idx = 0;

        while (true)
        {

            pivot_idx = partition_algo(nums, L, R);

            if (pivot_idx == k - 1)
            {
                break;
            }
            else if (pivot_idx > k - 1)
            {
                R = pivot_idx - 1;
            }
            else
            {
                L = pivot_idx + 1;
            }
        }

        return nums[pivot_idx];
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 3;
    cout << "Kth largest element is: " << solution.findKthLargest(nums, k) << endl;
    return 0;
}