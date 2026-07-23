#include <bits/stdc++.h>
using namespace std;

int search_sorted(vector<int> &nums, int x, int low, int high)
{
    //if array is empty
    if(nums.size()==0) return -1;

    if(low>high) return -1;

    int mid = (low + high) / 2;

    //base condition
    if (nums[mid]==x) return mid;

   
        //left part is sorted
        if (nums[low]<=nums[mid]){
            //checks if the target is present on the sorted(right) side
            if(x>=nums[low] && x<=nums[mid]) return search_sorted(nums,x,low,mid-1);
            else return search_sorted(nums,x,mid+1,high);

        }
        //right part is sorted
        else{
                //checks if the target is present on the sorted(left)side
                if(x>=nums[mid] && x<=nums[high]) return search_sorted(nums,x,mid+1,high);
                else return search_sorted(nums,x,low,mid-1);
        }
}



int main()
{
    vector<int> nums =  {4,5,6,7,0,1,2,4};
    int x=2;
    // vector<int>nums={};
    // int x=0;
    int count_ans = search_sorted(nums, x, 0, nums.size() - 1);
    
    cout<<"The number of occurrence "<<x<<" is : "<<count_ans<<endl;
    return 0;
}

// Time Complexity : O(logN) where N is the size of given array, and LogN is the time complexity for binary search.
// Space Complexity : O(logN) for stack function calls.