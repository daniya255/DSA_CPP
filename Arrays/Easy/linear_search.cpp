#include<iostream>
#include<vector>
using namespace std;
int linear_search(vector<int>&nums,int target){
    int n=nums.size();
    int ind=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            ind=i;
            break;
        }
    }
    return ind;
}
int main(){
    vector<int>nums={1,2,5,2,8,3,6};
    cout<<linear_search(nums,2);
    return 0;
}
   