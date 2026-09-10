class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
    vector<int>result(n,-1);
    stack<int> st;
    
    // Traverse 2 * n times to simulate the circular wrap-around
    for (int i = 2*n - 1; i >= 0; i--) {
        // Pop elements smaller than or equal to current element
        while (!st.empty() && st.top() <= nums[i%n]) {
            st.pop();
        }

        // Only record results during the actual first pass (indices 0 to n-1)
       if(i<n){
            if(!st.empty()){
                result[i]=st.top();
            }
       }
        
        // Push current element onto stack for future elements to check
        st.push(nums[i%n]);
    }

    return result;
    }
};