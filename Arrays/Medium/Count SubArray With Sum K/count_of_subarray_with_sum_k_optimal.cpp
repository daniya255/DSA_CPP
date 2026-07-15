#include<bits/stdc++.h>
using namespace std;
int count_subarray(vector<int>&nums,int s){
    int presum=0,count=0;
    int n=nums.size();
    unordered_map<int,int>mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        presum+=nums[i];
        int rem=presum-s;
        if(mpp.find(rem)!=mpp.end()) count+=mpp[rem];  
        mpp[presum]++;        
        
    }

    return count;
}
int main(){
    vector<int>nums={1,1,2,3,1,1,1,1,4,2,1,3};
    cout<<count_subarray(nums,4);
    return 0;
}

// Time Complexity: O(n) We traverse the array once, where n is the size of the array. Each prefix sum operation and hashmap lookup is O(1) on average.

// Space Complexity: O(n) In the worst case, all prefix sums are distinct and stored in the hashmap, so space grows linearly with input size.

