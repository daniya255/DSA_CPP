class Solution {
public:
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
    int splitArray(vector<int>& nums, int k) {
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
};