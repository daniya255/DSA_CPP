#include<bits/stdc++.h>
using namespace std;
vector<int>majority_element(vector<int>&nums){
    int n=nums.size();
    int count=0;
    vector<int>result;
    for(int i=0;i<n;i++){
        if(result.size()==0 || result[0]!=nums[i]){
            count=0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]) count++;
            }
            if(count>(n/3)) result.push_back(nums[i]);
        }
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


//Time Complexity: O(N^2), where N is the size of the array. This is because for each element, we are traversing the entire array to count its occurrences.
//Space Complexity: O(1), as we are using a constant amount of space for the result array, which can hold at most 2 elements.

