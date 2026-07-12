#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(cost,profit);
            mini=min(mini,prices[i]);
        }
        return profit;
    }

int main(){
    vector<int>prices={5,2,1,7,6,3};
    cout<<"Max profit : "<<maxProfit(prices);
    cout<<endl;

    return 0;
}


//Time Complexity : O(n) where n is the size of the input array
//Space Complexity : O(1) const space require for variables