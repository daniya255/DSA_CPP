#include<bits/stdc++.h>
using namespace std;
vector<int>rearrange_array(vector<int>&nums){
    int n=nums.size();
    int pos=0,neg=1;
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            ans[pos]=nums[i];
            pos+=2;;
        }
        else {
            ans[neg]=nums[i];
            neg+=2;
        }
    }


    return ans;
}
int main(){
    vector<int>nums={3,-2,-5,7,-9,-1,4,6};
    vector<int>nums_result=rearrange_array(nums);
    for(int val:nums_result) cout<<val<<" ";
    cout<<endl;
    return 0;
}


// Time Complexity: O(N) for traversing the array once 

// Space Complexity: O(N)  allocating one extra vector (ans) of size N