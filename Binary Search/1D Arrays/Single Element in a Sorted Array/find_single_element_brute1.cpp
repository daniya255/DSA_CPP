#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the single non-duplicate element
    int singleNonDuplicate(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // If array has only one element, return it
        if (n == 1) return arr[0];

        // Loop through the array
        for (int i = 0; i < n; i++) {

            // Check if it's the first element and not equal to the next
            if (i == 0) {
                if (arr[i] != arr[i + 1])
                    return arr[i];
            }

            // Check if it's the last element and not equal to the previous
            else if (i == n - 1) {
                if (arr[i] != arr[i - 1])
                    return arr[i];
            }

            // Check if the current element is not equal to both neighbors
            else {
                if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                    return arr[i];
            }
        }

        // Dummy return if no element found (problem guarantees there is one)
        return -1;
    }
};

// Driver code
int main() {
    // Input array with one unique element
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Create an object of Solution class
    Solution obj;

    // Call the function and store result
    int ans = obj.singleNonDuplicate(arr);

    // Print the result
    cout << "The single element is: " << ans << "\n";

    return 0;
}
