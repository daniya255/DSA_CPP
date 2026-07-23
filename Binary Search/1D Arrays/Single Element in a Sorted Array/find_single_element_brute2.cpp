#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the single non-duplicate element using XOR
    int singleNonDuplicate(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Initialize the result variable with 0
        int ans = 0;

        // Traverse the array and XOR all elements
        for (int i = 0; i < n; i++) {
            ans = ans ^ arr[i];
        }

        // Return the unique element found using XOR
        return ans;
    }
};

// Driver code
int main() {
    // Input array with all elements occurring twice except one
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Create an object of Solution class
    Solution obj;

    // Call the function and store the result
    int ans = obj.singleNonDuplicate(arr);

    // Print the result
    cout << "The single element is: " << ans << "\n";

    return 0;
}
