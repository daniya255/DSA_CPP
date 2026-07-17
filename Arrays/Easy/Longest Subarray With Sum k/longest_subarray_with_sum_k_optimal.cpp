#include<iostream>
#include<vector>
#include<map>
using namespace std;
int max_subarray(vector<int>&nums,int s){
    int maxlen=0,sum=nums[0];
    int right=0,left=0;
    int n=nums.size();
     while(right<n){
        while(left<=right && sum>s){
            sum-=nums[left];
            left++;
        }
        if(sum==s){
        maxlen=max(maxlen,right-left+1);
        }

        right++;
        if(right<n) sum+=nums[right];
        
     }
    return maxlen;
}
int main(){
    vector<int>nums={1,1,2,3,1,1,1,1,4,2,1,3};
    cout<<max_subarray(nums,2);
    return 0;
}

//Time Complexity : O(2n) where n is the number of elements of the input array 
//The complexity is 2n and not n*n because the inner while loop isnot transversing for n times in each iteration,rather it is iterating for 0,1,2...n , means it is iterating for n times in total not in each interation of the outer loop. 
//Space Complexity : O(1) const space required for varaibles