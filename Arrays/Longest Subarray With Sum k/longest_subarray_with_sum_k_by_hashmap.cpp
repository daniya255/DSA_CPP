#include<iostream>
#include<vector>
#include<map>
using namespace std;
int max_subarray(vector<int>&nums,int s){
    int maxlen=0,sum=0;
    int n=nums.size();
    map<int,int>presum;

    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==s){
            maxlen=max(maxlen,i+1);
        }

        int rem=sum-s;

        if(presum.find(rem)!=presum.end()){
            maxlen=max(maxlen,i-presum[rem]);
        }

        if(presum.find(sum)==presum.end()){
            presum[sum]=i;
        }
    }
    
    return maxlen;
}
int main(){
    vector<int>nums={1,1,2,3,1,1,1,1,4,2,1,3};
    cout<<max_subarray(nums,4);
    return 0;
}

//Time Complexity : O(nlogn) where n is the number of elements of the input array and logn is for ordered map
//Space Complexity : O(n) for hash map