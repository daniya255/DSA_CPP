#include <bits/stdc++.h>
using namespace std;

bool rotated_search(vector<int> &nums, int x, int low, int high)
{
    //if array is empty
    if(nums.size()==0) return false;

    if(low>high) return false;

    int mid = (low + high) / 2;

    //if low,mid and high have the same element , shrink the search space as it is not our desired result
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
           return rotated_search(nums,x,low+1,high-1);
        }

    //base condition
    if (nums[mid]==x) return true;

   
        //left part is sorted
        if (nums[low]<=nums[mid]){
            //checks if the target is present on the sorted(right) side
            if(x>=nums[low] && x<=nums[mid]) return rotated_search(nums,x,low,mid-1);
            else return rotated_search(nums,x,mid+1,high);

        }
        //right part is sorted
        else{
                //checks if the target is present on the sorted(left)side
                if(x>=nums[mid] && x<=nums[high]) return rotated_search(nums,x,mid+1,high);
                else return rotated_search(nums,x,low,mid-1);
        }
}



int main()
{
    vector<int> nums =  {2,5,6,0,0,1,2};
    int x=3;
    // vector<int>nums={};
    // int x=0;
    bool ans = rotated_search(nums, x,0,nums.size()-1);
    cout << ans << "\n";
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(logN) for stack function calls.