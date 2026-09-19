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

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty() ) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea=0;
    vector<int> heights (cols,0);

    for(int i=0; i<rows; i++){
        // Update histogram based on current row
        for(int j=0; j<cols; j++){
            if (matrix[i][j] == '1'){
                heights[j] += 1;
            }
            else{
                heights[j] = 0;
            }
        }

        maxArea = max (maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}
int main(){
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}

//Time Complexity: O(N*(M+M)), where N = total no. of rows and M = total no. of columns.
//Space Complexity: O(M), used for storing heights in array and stack.