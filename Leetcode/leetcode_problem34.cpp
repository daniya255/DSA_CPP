class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        // if array is empty
        if (nums.size() == 0)
            return {-1, -1};
        int n = nums.size();
        int low = 0, high = n - 1;
        int first = 0;
        int last = 0;

        // check for first occurrence of the target
        while (low <= high) {

            int mid = (low + high) / 2;

            // lower bound logic : low points towards the first occurrence of
            // the target after the loop ends
            if (nums[mid] >= x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        // checks if 'low' is within array bounds and low is pointing towards
        // the target edge case : x is greater than every element of array so
        // low points towards 'n' (ind error).
        first = (low < nums.size() && nums[low] == x) ? low : -1;

        low = 0, high = n - 1;

        // check for last occurrence of the target
        while (low <= high) {
            int mid = (low + high) / 2;

            // upper bound logic: low-1 points towards the last occurrence of
            // the target after the loop ends
            if (nums[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        // checks if 'low-1' is within array bounds and low-1 is pointing
        // towards target edge case : if x is smaller than every element, then
        // low stays at 0 so low-1=-1 (ind error)
        last = (low - 1 >= 0 && nums[low - 1] == x) ? low - 1 : -1;

        vector<int> ans{first, last};
        return ans;
    }
};