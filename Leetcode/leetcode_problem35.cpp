class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        // assume array is already sorted
        while (low <= high) {

            int mid = (low + high) / 2;

            // if mid element is smaller than target
            if (nums[mid] < x)
                low = mid + 1;

            // if mid element is equal or greater than target
            else
                high = mid - 1;
        }
        return low;
    }
};