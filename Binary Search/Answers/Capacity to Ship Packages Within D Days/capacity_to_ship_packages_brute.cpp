#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check how many days needed for given capacity
    int daysNeeded(vector<int>& weights, int capacity) {
        // Initialize day count to 1
        int days = 1;
        // Current load for the day
        int currentLoad = 0;

        // Iterate over all package weights
        for (int w : weights) {
            // If adding weight exceeds capacity
            if (currentLoad + w > capacity) {
                // Increase day count and reset load
                days++;
                currentLoad = w;
            } else {
                // Otherwise, add weight to current load
                currentLoad += w;
            }
        }
        // Return total days needed
        return days;
    }

    // Function to find minimum ship capacity to ship in d days
    int shipWithinDays(vector<int>& weights, int d) {
        // Find maximum weight as minimum capacity
        int left = *max_element(weights.begin(), weights.end());
        // Find total sum as maximum capacity
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Iterate from minimum to maximum capacity
        for (int capacity = left; capacity <= right; capacity++) {
            // Calculate days needed for current capacity
            int needed = daysNeeded(weights, capacity);
            // If days needed are less than or equal to d, return capacity
            if (needed <= d) {
                return capacity;
            }
        }
        // Should never reach here given constraints
        return right;
    }
};

int main() {
    // Input weights
    vector<int> weights = {5,4,5,2,3,4,5,6};
    // Days to ship
    int d = 5;
    // Create Solution instance
    Solution sol;
    // Call the function and print result
    cout << sol.shipWithinDays(weights, d) << "\n";
    return 0;
}

//Time Complexity: O((sum_weights - max_weight) * N), where N is the number of packages. For each capacity between max weight and total sum, we simulate shipping over N packages.
//Space Complexity: O(1), only constant extra space is used.