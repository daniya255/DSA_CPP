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

    int pSize = pos.size();
    int nSize = neg.size();
    int i = 0, j = 0, k = 0;

    // as long as both have elements
    while(i < pSize && j < nSize) {
        nums[k++] = pos[i++];
        nums[k++] = neg[j++];
    }

    // Append leftover positives, if any
    while(i < pSize) {
        nums[k++] = pos[i++];
    }

    // Append leftover negatives, if any
    while(j < nSize) {
        nums[k++] = neg[j++];
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
