#include <bits/stdc++.h>
using namespace std;

    // Function to calculate how many days are needed to ship packages with given capacity
    bool daysNeeded(vector<int>& weights, int capacity,int d) {
        // Initialize count of days to 1 (start with day one)
        int days = 1;

        // Variable to track the current load on the ship for a day
        int currentLoad = 0;

        // Loop through each package weight in the array
        for (int w : weights) {
            // Check if adding current package exceeds ship capacity for the day
            if (currentLoad + w > capacity) {
                // Need a new day to ship this package, so increment day count
                days++;

                // Start new day's load with current package weight
                currentLoad = w;
            } else {
                // If capacity not exceeded, add current package weight to the day's load
                currentLoad += w;
            }
        }

        // Return total number of days needed with this capacity
        return days<=d;
    }

    // Main function to find minimum capacity to ship all packages within d days
    int shipWithinDays(vector<int>& weights, int d) {
        // Find the maximum package weight as the minimum capacity (can't be less than this)
        int low = *max_element(weights.begin(), weights.end());

        // Calculate the sum of all package weights as maximum capacity (ship all at once)
        int high = accumulate(weights.begin(), weights.end(), 0);

        // Binary search loop to find optimal capacity between low and high
        while (low <= high) {
            // Calculate mid value as potential capacity to test
            int mid = (low + high) / 2;

            // Check if the current capacity is a possible answer
            bool check = daysNeeded(weights, mid,d);

            if (check) {
                high = mid-1;
            } else {
                // If days needed is more than allowed, increase capacity by moving left boundary
                low = mid + 1;
            }
        }

        // Low is now the minimum capacity that can ship packages within d days
        return low;
    }


int main() {
    // Define the package weights
    vector<int> weights = {5,4,5,2,3,4,5,6};

    // Define number of days within which packages must be shipped
    int d = 5;


    // Call the function and output the result
    cout << shipWithinDays(weights, d) << "\n";

    return 0;
}

//Time Complexity: O(N * log(S)), where N is number of packages and S is the search space (sum_weights - max_weight). Each binary search step takes O(N), repeated O(log S) times.
//Space Complexity: O(1), constant extra space used.