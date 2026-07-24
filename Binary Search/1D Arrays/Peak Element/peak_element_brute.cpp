#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find a peak element in the array
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Check left neighbor if exists
            bool left = (i == 0) || (nums[i] >= nums[i - 1]);
            // Check right neighbor if exists
            bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);
            
            // If both sides are valid, return index
            if (left && right) return i;
        }

        // In case no peak found (shouldn't happen)
        return -1;
    }
};

// Driver
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 20, 4, 1, 0};
    int index = sol.findPeakElement(nums);
    cout << "Peak at index: " << index << " with value: " << nums[index] << endl;
    return 0;
}

//Time Complexity: O(N), we traverse the entire array once to find peak element.
//Space Complexity: O(1), constant additional space is used.