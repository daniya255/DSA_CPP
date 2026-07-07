#include<iostream>
#include<vector>
using namespace std;
void move_zeroes(vector<int>&nums){
  
 int n=nums.size();
    int j=-1;
    
    for(int i=0;i<n;i++){
        if(nums[i]==0){
           j=i;
           break;
        }
    }

    if (j==-1) return;

    for(int i=j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
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