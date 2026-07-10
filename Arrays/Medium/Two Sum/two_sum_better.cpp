#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int>two_sum(vector<int>&nums,int target){
    int n=nums.size();
    map<int,int>hash;
   for(int i=0;i<n;i++){
        int rem=target-nums[i];
        if(hash.find(rem)!=hash.end()){
            return {hash[rem],i};
        }
        hash[nums[i]]=i;
   }
    return {0};
}
int main(){
    vector<int>nums={1,2,5,2,7,8,5};
    vector<int>result=two_sum(nums,8);
    for(int val:result){
        cout<<val<<" ";
    }
    
    return 0;
}

//Time Complexity : O(nlog n) where n is size of the input vector, incase of ordered map
//Space Complexity : O(n) because of hashmap