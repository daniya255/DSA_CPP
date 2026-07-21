#include<bits/stdc++.h>
using namespace std;
vector<int> floor_ceil(vector<int>&nums,int x){
    int n=nums.size();
   
    int floor_ans=INT_MIN;
    int ceil_ans=INT_MAX;
    
    //floor & ceil function
    for(int i=0;i<n;i++){
        //floor loop
        if(nums[i]<=x) floor_ans=max(floor_ans,nums[i]);

        //ceil loop
        if(nums[i]>=x) ceil_ans=min(ceil_ans,nums[i]);
    }
    
    vector<int>ans{floor_ans,ceil_ans};
    return ans;
    
    }

int main(){
    vector<int>nums={3,5,8,8,15,19};
    int x=9;
    vector<int>ans=floor_ceil(nums,x);
    cout<<"The floor of "<<x<<" is : "<<ans[0]<<endl;
    cout<<"The ceil of "<<x<<" is : "<<ans[1]<<endl;
    return 0;
}

//Time Complexity : O(N) where N is the size of given array, as linear search is used for searching the index.
//Space Complexity : O(1) const space is required for variables and 2 element vector.