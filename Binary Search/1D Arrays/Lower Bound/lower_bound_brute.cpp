#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&nums,int x){
    int n=nums.size();
    
    //assume array is already sorted
    for(int i=0;i<n;i++){
        if(nums[i]>=x) return i;
    }
    return n;
}
int main(){
    vector<int>nums={3,5,8,15,19};
    int x=9;
    cout<<"The lower bound of "<<x<<" is : "<<lower_bound(nums,x);
    return 0;
}

//Time Complexity : O(N) where N is the size of given array, as linear search is used for searching the index.
//Space Complexity : O(1) const space is required for variables.