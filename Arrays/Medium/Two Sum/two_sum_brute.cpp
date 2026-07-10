#include<iostream>
#include<vector>
using namespace std;
vector<int>two_sum(vector<int>&nums,int target){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i+1;j<n;j++){
            sum=nums[i]+nums[j];
            if(sum==target) {
                return {i,j};
            }

        }
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

//Time Complexity : O(n*n)(approx) where n is size of the input vector
//Space Complexity : O(1) because variables like n,sum takes const sapce and vector {i,j} always return two integers