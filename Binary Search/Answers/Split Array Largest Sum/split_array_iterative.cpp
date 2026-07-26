#include<bits/stdc++.h>
using namespace std;
// Counts how many partitions are needed for a given maxSum
int no_partitions(vector<int>&nums,int mid,int k){
    int n=nums.size();
    long long sum=0;    // at least one partition
    int partitions=1;   // sum of current subarray

    for(int num: nums){
        if(sum + num> mid) {
            partitions++;
            sum=num;
        }
        else sum+=num;
    }

    return partitions;
}
// Finds the minimum largest subarray sum possible for at most k partitions
int split_array(vector<int>&nums,int k){
    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    int possible_ans=low;

     // Binary search for the smallest maxSum
    while(low<=high){
        int mid=(low+high)/2;
        int partitions=no_partitions(nums,mid,k);

        // valid but try smaller maxSum
        if(partitions<=k){
            possible_ans=mid;
            high=mid-1;
    }
        // too many partitions → increase maxSum
        else low=mid+1;
}
    return possible_ans;

}
int main(){

    vector<int>nums= {10, 20, 30, 40};
    int k = 2;
    int ans=split_array(nums,k);
    cout<<"The answer is: " << ans << endl;
    return 0;
}

//Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
//Space Complexity: O(1), no extra space used