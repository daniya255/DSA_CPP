#include <bits/stdc++.h>
using namespace std;

// Class to solve the gas station placement problem
class Solution {
public:
    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // Tracks how many stations in each segment
        priority_queue<pair<long double, int>> pq; // Max-heap

        // Initially insert all segments into the heap with their lengths
        for (int i = 0; i < n - 1; i++) {
            long double length = arr[i + 1] - arr[i];
            pq.push({length, i});
        }

        // Place k additional gas stations
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            auto top = pq.top();
            pq.pop();
            int segmentIndex = top.second;

            // Add a station to the segment and recompute its length
            howMany[segmentIndex]++;
            long double totalDist = arr[segmentIndex + 1] - arr[segmentIndex];
            long double newLen = totalDist / (howMany[segmentIndex] + 1);
            pq.push({newLen, segmentIndex});
        }

        // Final answer is the max segment length at the top of the heap
        return pq.top().first;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    Solution obj;
    long double ans = obj.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

//Time Complexity: O(nlogn + klogn), n = size of the given array, k = no. of gas stations to be placed.
//Space Complexity: O(n-1)+O(n-1). The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue..