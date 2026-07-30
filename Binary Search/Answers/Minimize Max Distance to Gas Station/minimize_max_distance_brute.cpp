#include <bits/stdc++.h>
using namespace std;

// Class to solve the gas station placement problem
class GasStationSolver {
public:
    // Function to minimize the maximum distance after placing k gas stations
    long double minimiseMaxDistance(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // howMany[i]: extra stations between arr[i] and arr[i+1]

        // Place k gas stations one at a time
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            long double maxSection = -1;
            int maxInd = -1;

            // Find the segment with the current largest section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength = diff / (howMany[i] + 1.0);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            // Add a gas station in the largest segment
            howMany[maxInd]++;
        }

        // Find the final maximum distance after placing all gas stations
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    GasStationSolver solver;
    long double ans = solver.minimiseMaxDistance(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}

//Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations to be placed.
//Space Complexity: O(n-1) as we are using an array to keep track of placed gas stations
