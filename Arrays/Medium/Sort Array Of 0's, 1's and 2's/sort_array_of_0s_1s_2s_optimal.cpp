
// This approach is a direct implementation of the Dutch National Flag algorithm.

// We divide the array into three partitions using three pointers – low, mid, and high.
// From 0 to low-1, we’ll keep only 0s
// From low to mid-1, only 1s
// From high+1 to n-1, only 2
// The range from mid to high is the unsorted zone we’re scanning and fixing. At each step:
// If arr[mid] == 0, it belongs to the left section → swap with low, move both low and mid.
// If arr[mid] == 1, it’s already in the middle section → just move mid.
// If arr[mid] == 2, it belongs to the right section → swap with high, only move high.




#include <bits/stdc++.h>
using namespace std;
void sort_array(vector<int>&nums){
    int n=nums.size();
    int low=0,mid=0,high=n-1;

    while(mid<=high){
        if(nums[mid]==0) {
            swap(nums[low],nums[mid]);
            mid++,low++;
        }
        else if(nums[mid]==1) mid++;
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }

}


int main(){
    vector<int>nums={0,1,1,2,1,1,0,2,1,0,1,1,2};
    sort_array(nums);
    for(int val:nums){
        cout<<val<<" ";
    }
    return 0;
}

//Time Complexity: O(n) The array is traversed only once using the `mid` pointer. Each element is checked at most once, and swaps are done in constant time.

//Space Complexity: O(1) Only a few integer pointers (`low`, `mid`, `high`) are used. Sorting is done in-place, requiring no additional space.