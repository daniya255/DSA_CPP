#include<bits/stdc++.h>
using namespace std;
vector<int> majority_element(vector<int>&nums){
    vector<int>result;
    unordered_map<int,int>mpp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]]>(n/3)) result.push_back(nums[i]);
        if(result.size()==2) break;
    }
    return result;
}
int main(){
    vector<int>nums={1,1,1,2,2,3,3,3};
    vector<int>result=majority_element(nums);
    for(int val:result) cout<<val<<endl;
    return 0;
}

//Time Complexity: O(N * logN), where N is the size of the given array. For using a map data structure, where insertion in the map takes logN time, and we are doing it for N elements. So, it results in the first term O(N * logN). On using unordered_map instead, the first term will be O(N) for the best and average case, and for the worst case, it will be O(N2).
//Space Complexity: O(N) for using a map data structure. A list that stores a maximum of 2 elements is also used, but that space used is so small that it can be considered constant.

