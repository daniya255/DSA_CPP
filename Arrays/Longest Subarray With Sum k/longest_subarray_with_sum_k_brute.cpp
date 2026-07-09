#include<iostream>
#include<vector>
using namespace std;
int max_subarray(vector<int>&nums,int s){
    int maxlen=0,sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
            sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==s){
                maxlen=max(maxlen,j-i+1);
            }
        }     
        }

    return maxlen;
}
int main(){
    vector<int>nums={1,1,2,3,1,1,1,1,4,2,1,3};
    cout<<max_subarray(nums,4);
    return 0;
}

//Time Complexity : O(n*n) where n is the number of elements of the input array (nested loop)
//Space Complexity : O(1) constant space required for variables like 'n', 'maxlen', 'sum'