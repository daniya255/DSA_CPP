class Solution {
public:
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

    
};