#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>result;
    if (nums.empty() || k==0) return result;
    for(int i=0; i<=nums.size()-k; i++){
        int maxi = INT_MIN;
        for(int j=i; j<i+k;j++){
            maxi = max(maxi,nums[j]);
        }
        result.push_back(maxi);
    }

    return result;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>result = maxSlidingWindow(nums,k);
    for(int i: result) cout<<i<<" ";
    return 0;
}

//Time Complexity : O(n*k) where n is size of input array and k is the size of the window
//Space Complexity : O(1) because no  auxiliary space is used for solvng the problem