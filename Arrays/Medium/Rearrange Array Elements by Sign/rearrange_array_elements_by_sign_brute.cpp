#include<bits/stdc++.h>
using namespace std;
vector<int>rearrange_array(vector<int>&nums){
    int n=nums.size();
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(nums[i]<0) neg.push_back(nums[i]);
        else pos.push_back(nums[i]);
    }

    for(int i=0;i<n/2;i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }

    return nums;
}
int main(){
    vector<int>nums={3,-2,-5,7,-9,-1,4,6};
    vector<int>nums_result=rearrange_array(nums);
    for(int val:nums_result) cout<<val<<" ";
    cout<<endl;
    return 0;
}


// Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.

// Space Complexity: O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.