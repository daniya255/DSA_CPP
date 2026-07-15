#include <bits/stdc++.h>
using namespace std;
vector<int> spiral_matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m=matrix[0].size();
    vector<int> ans;

    int top = 0, left = 0;
    int bottom = n - 1, right = m - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}
int main()
{
    vector<vector<int>> matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int>result=spiral_matrix(matrix);
        for(int val : result) {
        cout << val << " ";
    }


    return 0;
}

// Time Complexity: O(m × n),Because we visit each element of the matrix exactly once, where `n` is the number of rows and `m` is the number of columns.

// Space Complexity: O(1)We use only a few integer variables to keep track of boundaries (top, bottom, left, right). The `result` vector is part of the output, so it's not counted as extra space.

