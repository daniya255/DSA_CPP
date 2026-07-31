#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search for a target value in the matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get number of rows in the matrix
        int n = matrix.size();

        // Get number of columns in the matrix
        int m = matrix[0].size();

        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Traverse each column in the current row
            for (int j = 0; j < m; j++) {
                // Check if the current element matches the target
                if (matrix[i][j] == target)
                    return true;
            }
        }

        // Return false if the target is not found
        return false;
    }
};

// Driver code
int main() {
    // Define a 2D matrix
    vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                  {5, 6, 7, 8}, 
                                  {9, 10, 11, 12}};

    // Create an object of the Solution class
    Solution obj;

    // Call the searchMatrix function and print the result
    if (obj.searchMatrix(matrix, 8)) 
        cout << "true\n";
    else 
        cout << "false\n";

    return 0;
}

//Time Complexity: O(n × m), We are traversing the entire matrix with `n` rows and `m` columns. In the worst case, we may end up visiting every cell once if the target is not present. So, the total number of operations is proportional to the number of elements in the matrix.
//Space Complexity: O(1),We are not using any additional space. The algorithm uses a constant amount of extra memory regardless of the size of the matrix just loop variables and the target. Therefore, the space complexity is constant.