#include <bits/stdc++.h>
using namespace std;
//check for first occurrence of the target
int first_ind(vector<int> &nums, int x, int low, int high)
{
    //if array is empty
    if(nums.size()==0) return -1;

    //base condition
    if (low > high)
    {
       //checks if 'low' is within array bounds and low is pointing towards the target 
        //edge case : x is greater than every element of array so low points towards 'n' (ind error).
        return (low<nums.size() && nums[low]==x) ? low : -1;
    }

    int mid = (low + high) / 2;

    // lower bound logic : low points towards the first occurrence of the target after the loop ends
    if (nums[mid] >= x)
        return first_ind(nums, x, low, mid - 1);

    // Too small, look right!
    else
        return first_ind(nums, x, mid + 1, high);
}

//check for last occurrence of the target
int last_ind(vector<int> &nums, int x, int low, int high)
{
    //if array is empty
    if(nums.size()==0) return -1;
    
    //base condition
    if (low > high)
    {
        //checks if 'low-1' is within array bounds and low-1 is pointing towards target
        //edge case : if x is smaller than every element, then low stays at 0 so low-1=-1 (ind error)
        return (low-1>=0 && nums[low-1]==x) ? low-1 : -1;
        
    }

    int mid = (low + high) / 2;

    //upper bound logic: low-1 points towards the last occurrence of the target after the loop ends
    if (nums[mid] > x)
        return last_ind(nums, x,low, mid-1);

    //move low towards right
    else
        return last_ind(nums, x, mid+1, high);
}

int main()
{
    vector<int> nums = {3, 4, 4, 5, 8, 15, 19};
    int x = 4;
    // vector<int>nums={};
    // int x=0;
    int first = first_ind(nums, x, 0, nums.size() - 1);
    int last = last_ind(nums, x, 0, nums.size() - 1);
     cout<<"The first occurence of "<<x<<" is : "<<first<<endl;
    cout<<"The last occurrence of "<<x<<" is : "<<last<<endl;
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(logN) for stack function calls.