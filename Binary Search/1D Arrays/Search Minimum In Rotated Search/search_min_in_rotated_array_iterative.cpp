#include <bits/stdc++.h>
using namespace std;
// assume array is already sorted
int min_search(vector<int> &nums)
{
    //if array is empty
    if(nums.size()==0) return -1;
    int n = nums.size();
    int low = 0, high = n - 1;
    int mini=INT_MAX;
   
    while (low <= high)
    {

        int mid = (low + high) / 2;

       
        //left part is sorted
        if (nums[low]<=nums[mid]){
           //store the minimum element on the left side, i.e:(low) if it is smaller than mini
            mini=min(nums[low],mini);
            low=mid+1;

        }
        
        //right part is sorted
        else{
                //store the minimum element of the right side, i.e:(mid) if it is smaller than mini
                mini=min(nums[mid],mini);
                high=mid-1;
        }
    }
    
    return mini;

}

int main()
{
    vector<int> nums =  {4,5,6,7,8,9,2,3};
    // vector<int>nums={};
    int ans = min_search(nums);
    cout <<"The minimum element is : "<< ans << "\n";
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(1) const space is required for variables.