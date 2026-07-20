#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&nums,int x,int low,int high){
    // Base case: when pointers cross, 'low' will naturally point 
    // to the smallest index satisfying nums[index] >= x.
   if (low>high) return low;

    int mid=(low+high)/2;

    // Find the first index of element greater than target or the first occurrance of the target
    if(nums[mid]>=x) return lower_bound(nums,x,low,mid-1);

    // Too small, look right!
   else return lower_bound(nums,x,mid+1,high);

}
int main(){
    vector<int>nums={2,3,4,4,5,8,19};
    int x=4;
    cout<<"The lower bound of "<<x<<" is : "<<lower_bound(nums,x,0,nums.size()-1);
    return 0;
}

//Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
//Space Complexity : O(logN) for stack function calls.