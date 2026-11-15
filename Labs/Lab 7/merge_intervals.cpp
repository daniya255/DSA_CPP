#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> merged;
    for (const auto& interval : intervals) {
        // If the merged list is empty or current interval does not overlap, push it
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            // Otherwise, merge the current interval with the previous one
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}