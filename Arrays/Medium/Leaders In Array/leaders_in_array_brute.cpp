#include<bits/stdc++.h>
using namespace std;
vector<int>leaders_array(vector<int>&nums){
    int n=nums.size();
    vector<int>leaders;
    bool leader;
    for(int i=0;i<n;i++){
        leader=true;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]){
                leader=false;
                break;
            }
        }
        if(leader==true) leaders.push_back(nums[i]);
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



//Time Complexity : O(N*N) where N is the size of the input array, and N*N is because we are running a nested loop.
//Space Complexity : O(N) in worst case, if all are leaders.