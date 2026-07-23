class Solution {
public:
    bool search(vector<int>& nums, int x) {
        //if array is empty
    if(nums.size()==0) return false;
    int n = nums.size();
    int low = 0, high = n - 1;
   
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if(nums[mid]==x) return true;

        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
        }


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
    
    return false;
    }
};