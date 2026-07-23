#include <bits/stdc++.h>
using namespace std;

int min_search(vector<int> &nums,int low, int high)
{
    int mini=INT_MAX;

    //base condition no 1
    if(nums.empty() || low>high) return mini;

    //base condition no 2
    if(nums[low]<=nums[high]) return nums[low];

    int mid = (low + high) / 2;

        //left part is sorted
        if (nums[low]<=nums[mid]){
            mini=min(mini,nums[low]);
            return min_search(nums,mid+1,high);

        }
        //right part is sorted
        else{
            mini=min(nums[mid],mini);
            return min_search(nums,low,mid-1);
        }
}



int main()
{
  vector<int> nums =  {4,5,6,7,8,9,2,3};
    // vector<int>nums={};
    int ans = min_search(nums,0,nums.size()-1);
    cout <<"The minimum element is : "<< ans << "\n";
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(logN) for stack function calls.