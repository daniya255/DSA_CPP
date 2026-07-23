#include <bits/stdc++.h>
using namespace std;
// assume array is already sorted
int single_search(vector<int> &nums)
{
    int n = nums.size();

    //if array is empty
    if(n==0) return -1;

    //if array contains only one element
    if(n==1) return nums[0];

    //check for 1st element
    if(nums[0]!=nums[1]) return nums[0];

    //check for the last element
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    
    //low=1 because first element is already checked and high=n-2 bcz last element is checked
    int low = 1, high = n - 2;
   
    while (low <= high)
    {

        int mid = (low + high) / 2;

        // Check if middle element is the unique one
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        
        // If mid is in the left half (pairing is valid)
        if((nums[mid]==nums[mid-1] && mid%2==1) || (nums[mid]==nums[mid+1] && mid%2==0))
         // Move to the right half
            low=mid+1;
            
        // If mid is in the right half (pairing broken earlier)    
        else 
         // Move to the left half
            high=mid-1;      
    }

    
    return -1;

}

int main()
{
    vector<int> nums =  {3,3,7,7,10,11,11};
    int ans= single_search(nums);
    cout << ans << "\n";
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(1) const space is required for variables.