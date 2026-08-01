#include <bits/stdc++.h>
using namespace std;

vector<int> peak_element(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low_col = 0, high_col = m - 1;

    while (low_col <= high_col) {
        int mid_col = low_col + (high_col - low_col) / 2;

        // Find the row with the maximum value in the current middle column
        int max_row = 0;
        int max_val = matrix[0][mid_col];

        for (int row = 1; row < n; row++) {
            if (matrix[row][mid_col] > max_val) {
                max_val = matrix[row][mid_col];
                max_row = row;
            }
        }

        // Check left and right neighbors safely with boundary checks
        bool left_is_big = (mid_col > 0 && matrix[max_row][mid_col - 1] > max_val);
        bool right_is_big = (mid_col < m - 1 && matrix[max_row][mid_col + 1] > max_val);

        // If neither neighbor is bigger, it's a peak!
        if (!left_is_big && !right_is_big) {
            return {max_row, mid_col};
        }
        // If the left neighbor is bigger, search the left half
        else if (left_is_big) {
            high_col = mid_col - 1;
        }
        // Otherwise, search the right half
        else {
            low_col = mid_col + 1;
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}
    };

    vector<int> peak = peak_element(matrix);
    cout << "The row of peak element is " << peak[0]<< " and column of the peak element is " << peak[1] << endl;

    return 0;
}