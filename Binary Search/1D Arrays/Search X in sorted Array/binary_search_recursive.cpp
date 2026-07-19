#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&nums,int target,int low,int high){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) return binary_search(nums,target,mid+1,high);

    return binary_search(nums,target,low,mid-1);

}
int main(){
    vector<int>nums={-1,0,3,5,9,12};
    int target=3;
    int result=binary_search(nums,target,0,nums.size()-1);
    cout<<"The returned index is : "<<result;
    return 0;
}

/*Time Complexity: In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity. So the overall time complexity is O(logN), where N = size of the given array.
Space Complexity: O(log n) (Auxiliary Stack Space) —  Because each recursive call opens a new layer in the computer's memory stack, and you make a maximum of log_2(n) calls before stopping, the computer uses memory proportional to (log n).*/
