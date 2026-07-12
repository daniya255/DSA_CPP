class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        // Find the first decreasing element from end
        for (int i = n - 2; i >= 0; i--) {
            // If a smaller element found
            if (nums[i] < nums[i + 1]) {
                // Store index
                ind = i;
                break;
            }
        }
        // If no such index found
        if (ind == -1) {
            // Reverse the entire array
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find element just greater than nums[index]
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Reverse the part after index
        reverse(nums.begin() + ind + 1, nums.end());
    }
};