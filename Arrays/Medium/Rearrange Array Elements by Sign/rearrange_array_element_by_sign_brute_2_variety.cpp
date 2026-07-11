#include<bits/stdc++.h>
using namespace std;
vector<int>rearrange_array(vector<int>&nums){
    int n=nums.size();
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
       int  index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            nums[index]=pos[i];
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
       int  index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            nums[index]=neg[i];
        }
    }
   

    return nums;
}
int main(){
    vector<int>nums={3,-2,-5,7,-9,-1,4,6,-1,-2};
    vector<int>nums_result=rearrange_array(nums);
    for(int val:nums_result) cout<<val<<" ";
    cout<<endl;
    return 0;
}


// Time Complexity: O(N) + O(min(pos,neg)) + O(leftover):
// O(N) + O(0) + O(N) = O(N)

// Space Complexity: O(N)  allocating one extra vector for pos and neg
//Worst case : all elements are either positive or negative (N)