#include <bits/stdc++.h>
using namespace std;

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

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity: O(N + M) where N is the size of nums2 and $M$ is the size of nums1. Traversing nums2 from right to left takes $O(N)$ time because each element is pushed and popped from the stack at most once. Looking up the answers for nums1 in the hash map takes O(M) time
Space Complexity: O(N) to store the hash map and the monotonic stack for nums2.
*/