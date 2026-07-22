#include <bits/stdc++.h>
using namespace std;
// assume array is already sorted
int rotated_search(vector<int> &nums, int x)
{
    //if array is empty
    if(nums.size()==0) return -1;
    int n = nums.size();
    int low = 0, high = n - 1;
   
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if(nums[mid]==x) return mid;


        //left part is sorted
        if (nums[low]<=nums[mid]){
            //checks if the target is present on the sorted(right) side
            if(x>=nums[low] && x<=nums[mid]) high=mid-1;
            else low=mid+1;

        }
        //right part is sorted
        else{
                //checks if the target is present on the sorted(left)side
                if(x>=nums[mid] && x<=nums[high]) low=mid+1;
                else high=mid-1;
        }
    }
    
    return -1;

}

int main()
{
    vector<int> nums =  {4,5,6,7,0,1,2,4};
    int x=3;
    // vector<int>nums={};
    // int x=0;
    int ans = rotated_search(nums, x);
    cout << "The index of the target in the rotated array is: "<< ans << "\n";
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(1) const space is required for variables.