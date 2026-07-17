#include<iostream>
#include<vector>
using namespace std;
int consecutive_ones(vector<int>&nums){
    int maxi=0,count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==1) {
            count++;
            maxi=max(maxi,count);
        }
        else{
            count=0;
        }
    }
    return maxi;
}
int main(){
    vector<int>nums={1,1,0,0,0,1,1,1,1,0,1};
    cout<<consecutive_ones(nums);
    return 0;

}