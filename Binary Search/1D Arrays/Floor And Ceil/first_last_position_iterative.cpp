#include <bits/stdc++.h>
using namespace std;
vector<int> floor_ceil(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int floor_ans = INT_MIN;
    int ceil_ans = INT_MAX;
    // assume array is already sorted
    while (low <= high)
    {

        int mid = (low + high) / 2;

        // if mid element is smaller than target
        if (nums[mid] >= x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    //checks if 'low' is within array bounds
    ceil_ans = (low<n) ? nums[low] : -1;

    low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] <= x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    //checks if 'high' is within array bounds
    floor_ans = (high>=0) ? nums[high] : -1;

    vector<int> ans{floor_ans, ceil_ans};
    return ans;
}

int main()
{
    vector<int> nums = {3, 4, 4, 5, 8, 15, 19};
    int x = 9;
    vector<int> ans = floor_ceil(nums, x);
    cout << "The floor of " << x << " is : " << ans[0] << endl;
    cout << "The ceil of " << x << " is : " << ans[1] << endl;
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(1) const space is required for variables.
