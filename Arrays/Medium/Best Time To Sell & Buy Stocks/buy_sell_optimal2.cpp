#include<bits/stdc++.h>
using namespace std;

int buy_sell(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);   // Track the lowest price so far
        maxProfit = max(maxProfit, price - minPrice); // Check profit if we sell today
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = buy_sell(prices);
    cout << result << endl; // Output: 5
    return 0;
}
