#include<iostream>
#include<vector>
using namespace std;
int count_subarray(vector<int>&nums,int s){
    int count=0,sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
            sum+=nums[k];
            }
             if(sum==s) count++;
             
        }
    }

    return count;
}
int main(){
    vector<int>nums={1,1,2,3,1,1,1,1,4,2,1,3};
    cout<<count_subarray(nums,4);
    return 0;
}

//Time Complexity : O(n*n*n) where n is the number of elements of the input array.
//Space Complexity : O(1) constant space required for variables like 'n', 'count', 'sum'