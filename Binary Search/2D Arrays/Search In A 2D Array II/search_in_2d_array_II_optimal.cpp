#include <bits/stdc++.h>
using namespace std;

    // Function to search target in a 2D matrix using binary search over a virtual 1D array
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows
        int n = matrix.size();

        // Get the number of columns
        int m = matrix[0].size();

        // Set initial binary search range over the imaginary 1D array
        int row = 0, col=m-1;

        // Perform binary search
        while (row<n && col>=0) {

            // Check if the target is found
            if (matrix[row][col] == target)
                return true;
 
            // If the target is greater, discard the left half
            else if (matrix[row][col] < target)
                row++;

            // If the target is smaller, discard the right half
            else
                col--;;
        }

        // If not found, return false
        return false;
    }

// Driver code
int main() {
    // Define a 2D matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    // Call the function and print result
    if (searchMatrix(matrix, 21))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}

//Time Complexity: O(N+M), where N = given row number, M = given column number. We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0). So, the total distance can be at most (N+M). So, the time complexity is O(N+M).
//Space Complexity: O(1) as we are not using any extra space.

