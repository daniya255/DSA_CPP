#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&nums,int x){
    int n=nums.size();
    int low=0,high=n-1;
    //assume array is already sorted
    while(low<=high){

        int mid=(low+high)/2;
        
        //if mid element is smaller than target
        if (nums[mid]<x) low=mid+1;

        //if mid element is equal or greater than target
        else high=mid-1;
    }
    return low;
}
int main(){
    vector<int>nums={3,4,4,5,8,15,19};
    int x=4;
    cout<<"The lower bound of "<<x<<" is : "<<lower_bound(nums,x);
    return 0;
}

//Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
//Space Complexity : O(1) const space is required for variables.