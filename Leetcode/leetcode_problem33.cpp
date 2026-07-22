class Solution {
public:
    int search(vector<int>& nums, int x) {

        // if array is empty
        if (nums.size() == 0)
            return -1;
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == x)
                return mid;

            // left part is sorted
            if (nums[low] <= nums[mid]) {
                if (x >= nums[low] && x <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;

            }
            // right part is sorted
            else {
                if (x >= nums[mid] && x <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};