class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // transposing the matrix first
        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reversing the rows after transpose
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(),
                    matrix[i].end()); // take linear time complexity to reverse the entire row
        }
    }
};