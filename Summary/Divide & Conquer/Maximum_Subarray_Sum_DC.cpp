#include <iostream>
#include <climits>
using namespace std;

// Function to find the maximum sum of subarray crossing the middle
int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;

    // Traverse left half from mid to low
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN;
    sum = 0;

    // Traverse right half from mid+1 to high
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return the sum of elements crossing the middle
    return left_sum + right_sum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubArraySum(int arr[], int low, int high)
{
    // Base case: only one element
    if (low == high)
        return arr[low];

    // Find middle point
    int mid = (low + high) / 2;

    // Recursively find maximum sum in left, right, and crossing subarrays
    int left_sum = maxSubArraySum(arr, low, mid);
    int right_sum = maxSubArraySum(arr, mid + 1, high);
    int cross_sum = maxCrossingSum(arr, low, mid, high);

    // Return the maximum of the three
    return max(max(left_sum, right_sum), cross_sum);
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << max_sum << endl;

    return 0;
}
