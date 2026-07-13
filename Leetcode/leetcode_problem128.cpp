class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // If the array is empty
        if (n == 0)
            return 0;

        int longest = 0, count = 0;

        unordered_set<int> st;

        // Put all the array elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        /* Traverse the set to find the longest sequence  */
        for (auto it : st) {

            // Check if 'it' is a starting number of a sequence
            if (st.find(it - 1) == st.end()) {
                count = 1;
                int x = it;
                // Find consecutive numbers in the set
                while (st.find(x + 1) != st.end()) {
                    x++;
                    count++;
                }
            }

            longest = max(longest, count);
        }

        return longest;
    }
};