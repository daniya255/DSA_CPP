#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the smallest divisor such that
    // the sum of ceil(arr[i] / d) over all i <= limit
    int smallestDivisor(vector<int>& arr, int limit) {
        int n = arr.size(); // Size of the array

        // Find the maximum element in the array
        int maxi = *max_element(arr.begin(), arr.end());

        // Try every possible divisor from 1 to maxi
        for (int d = 1; d <= maxi; d++) {
            int sum = 0;

            // For each element, compute ceil(arr[i] / d) and add to sum
            for (int i = 0; i < n; i++) {
                sum += ceil((double)(arr[i]) / (double)(d));
            }

            // If the total sum is within the limit, return this divisor
            if (sum <= limit) {
                return d;
            }
        }

        // If no valid divisor is found, return -1
        return -1;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;

    Solution obj;
    int ans = obj.smallestDivisor(arr, limit);

    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}

//Time Complexity: O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array. We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.
//Space Complexity: O(1). No extra space used