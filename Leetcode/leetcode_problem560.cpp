class Solution {
public:
    int subarraySum(vector<int>& nums, int s) {
        int count=0,sum=0;
    int n=nums.size();
    map<int,int>presum;
    presum[0]=1;
    for(int i=0;i<n;i++){
        sum+=nums[i];

        int rem=sum-s;

        if(presum.find(rem)!=presum.end()){
            count+=presum[rem];
        }

        presum[sum]++;
    }
    return count;
}
};