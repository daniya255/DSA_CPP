class Solution {
public:
    long long sumMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        long long totalSum = 0;

        // finding PSE(Previous Smaller Element)
        for (int i = 0; i < n; i++) {
            // uisng stack to check if there is a smaller element before or not
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            // check if current is smallest or an other element before it
            left[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        // emptying stack for NSE
        while (!st.empty())
            st.pop();

        // finding NSE from right to left
        for (int i = n - 1; i >= 0; i--) {
            // checking for NSE by comparing current element with the elements
            // in stack
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            // check if there is a NSE or not, if not the current element can
            // stretch till end
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            // finding left boundary
            long long leftCount = i - left[i];
            // finding right boundary
            long long rightCount = right[i] - i;
            // finding total subarrays and multiplying them to the value
            long long contribution =
                (long long)nums[i] * leftCount * rightCount;
            totalSum += contribution;
        }

        return totalSum;
    }

    long long sumMaxs(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        long long totalSum = 0;

        // finding PLE(Previous Larger Element)
        for (int i = 0; i < n; i++) {
            // uisng stack to check if there is a larger element before or not
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            // check if current is largest or an other element before it
            left[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        // emptying stack for NLE
        while (!st.empty())
            st.pop();

        // finding NLE from right to left
        for (int i = n - 1; i >= 0; i--) {
            // checking for NLE by comparing current element with the elements
            // in stack
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            // check if there is a NLE or not, if not the current element can
            // stretch till end
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            // finding left boundary
            long long leftCount = i - left[i];
            // finding right boundary
            long long rightCount = right[i] - i;
            // finding total subarrays and multiplying them to the value
            long long contribution =
                (long long)nums[i] * leftCount * rightCount;
            totalSum += contribution;
        }

        return totalSum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumMaxs(nums);
        long long minSum = sumMins(nums);

        // Subtract minSum from maxSum
        return maxSum - minSum;
    }
};