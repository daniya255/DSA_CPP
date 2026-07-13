#include<bits/stdc++.h>
using namespace std;
vector<int>leaders_array(vector<int>&nums){
    int n=nums.size();
    int maxi=INT_MIN;
    vector<int>leaders;
    for(int i=n-1;i>=0;i--){
       if(nums[i]>maxi){
        leaders.push_back(nums[i]);
        maxi=max(maxi,nums[i]);
       }
            
    }
    return leaders;
}
int main(){
    vector<int>nums={10,12,22,3,5,6,2};
    vector<int>leaders=leaders_array(nums);
    for(int val: leaders) cout<<val<<" ";
    cout<<endl;
    return 0;
}



//Time Complexity : O(N) where N is the size of the input array.
//Space Complexity : O(N) in worst case, if all are leaders.