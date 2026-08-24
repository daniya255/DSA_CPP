#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate max profit using brute force
    int stockbuySell(vector<int>& prices) {
        // Initialize max profit to 0
        int maxProfit = 0;

        // Loop through each day as a potential buy day
        for(int i = 0; i < prices.size(); i++) {
            // Loop through each future day as a potential sell day
            for(int j = i + 1; j < prices.size(); j++) {
                // Calculate the profit
                int profit = prices[j] - prices[i];

                // Update max profit if this is higher
                maxProfit = max(maxProfit, profit);
            }
        }

        // Return the maximum profit
        return maxProfit;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.stockbuySell(prices) << endl;
    return 0;
}


// Time Complexity: O(n²) Because for each element, we are checking every future element nested loops.
// Space Complexity: O(1) No extra space used, only variables for storing max profit.