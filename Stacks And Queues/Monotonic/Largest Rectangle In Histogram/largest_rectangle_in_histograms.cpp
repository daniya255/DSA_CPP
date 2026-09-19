#include<bits/stdc++.h>
using namespace std;
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
int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int area = largestRectangleArea(heights);
    cout<<"The area of the of the largest rectangle in the histogram is : "<<area<<endl;
    return 0;
}

//Time Complexity: O(N) : The total number of stack operations across the entire array is at most 2N, making the time complexity linear.
//Space Complexity : O(N) in worst case scenerio we store all elements (eg. increasing array)