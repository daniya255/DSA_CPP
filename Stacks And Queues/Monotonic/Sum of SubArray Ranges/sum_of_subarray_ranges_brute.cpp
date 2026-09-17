#include<bits/stdc++.h>
using namespace std;
long long subArrayRanges(vector<int>& nums) {
    long long sum=0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int k=i; k<=j; k++){
                mini=min(mini,nums[k]);
                maxi=max(maxi,nums[k]);
            }
            sum+=(maxi - mini);
        }
    }

    return sum;
}
int main(){
    vector<int>nums = {4,-2,-3,4,1};
    cout<<"The sum of the ranges of the subarrays is  : "<<subArrayRanges(nums)<<endl;
    return 0;
}