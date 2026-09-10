class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        // 1. Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Pop elements smaller than or equal to current element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists (-1)
            // Otherwise, the top of the stack is the next greater element
            if (st.empty()) {
                ngeMap[nums2[i]] = -1;
            } else {
                ngeMap[nums2[i]] = st.top();
            }

            // Push current element onto stack for future elements to check
            st.push(nums2[i]);
        }

        // 2. Build the result for nums1 using our precomputed map
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(ngeMap[nums1[i]]);
        }

        return result;
    }
};