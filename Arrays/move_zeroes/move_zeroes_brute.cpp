#include<iostream>
#include<vector>
using namespace std;
void move_zeroes(vector<int>&nums){
    int n=nums.size();
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        nums[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        nums[i]=0;
    }

}
int main(){
    vector<int>nums={2,4,0,0,6,3,0,6,8};
    move_zeroes(nums);
    for(int val:nums){
        cout<<val<<" ";
    }
    return 0;
}