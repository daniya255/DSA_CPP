class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
    int maxArea = 0;
    int n = heights.size();

    for(int i=0;i<=n;i++){
        int curr = (i==n) ? 0 : heights[i];

        while(!st.empty() && heights[st.top()] > curr){
            int mid = st.top();
            st.pop();

            int right_boundary = i;
            int left_boundary = st.empty() ? -1 : st.top();

            int width = right_boundary - left_boundary -1;
            int area = width * heights[mid];
            maxArea = max(maxArea,area);
        }
        
        st.push(i);
    }

    return maxArea;
    }
};