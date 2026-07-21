#include <bits/stdc++.h>
using namespace std;
int find_ceil(vector<int> &nums, int x, int low, int high)
{
    // Base case: when pointers cross, 'low' will naturally point
    // to the smallest index satisfying nums[index] >= x.
    if (low > high)
    {
        //checks if 'low' is within array bounds
        return (low < nums.size()) ? nums[low] : -1;
    }

    int mid = (low + high) / 2;

    // Find the first index of element greater than target or the first occurrance of the target
    if (nums[mid] >= x)
        return find_ceil(nums, x, low, mid - 1);

    // Too small, look right!
    else
        return find_ceil(nums, x, mid + 1, high);
}

int find_floor(vector<int> &nums, int x, int low, int high)
{
    // Base case: when pointers cross, 'high' will naturally point
    // to the greatest index satisfying nums[index] <= x.
    if (low > high)
    {
        //checks if 'high' is within array bounds
        return (high >= 0) ? nums[high] : -1;
    }

    int mid = (low + high) / 2;

    // Find the  index of greatest element smaller than target or the first occurrance of the target
    if (nums[mid] <= x)
        return find_floor(nums, x, mid + 1, high);

    // Too large, look left!
    else
        return find_floor(nums, x, low, mid - 1);
}

int main()
{
    vector<int> nums = {3, 4, 4, 5, 8, 15, 19};
    int x = 9;
    int ceil_ans = find_ceil(nums, x, 0, nums.size() - 1);
    int floor_ans = find_floor(nums, x, 0, nums.size() - 1);
    cout << "The floor of " << x << " is : " << floor_ans << endl;
    cout << "The ceil of " << x << " is : " << ceil_ans << endl;
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(logN) for stack function calls.