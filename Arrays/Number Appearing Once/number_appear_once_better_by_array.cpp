#include<iostream>
#include<vector>
using namespace std;
int number_appearing_once(vector<int>&nums){
    int n=nums.size();
    int maxi=0;

    for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);
    }  

    int hash[maxi+1]={0};

    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }

    for(int i=0;i<n;i++){
        if(hash[nums[i]]==1)
            return nums[i];
    }

    return -1;
   
}
int main(){
    vector<int>nums={1,1,2,2,3,4,4,5,5};
    cout<<number_appearing_once(nums);
    return 0;
}

//Time Complexity : O(3n) where n is the size of the input vector
//Space Complexity : O(max +1 ) where max is the maximum element in the array
