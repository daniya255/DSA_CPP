#include<bits/stdc++.h>
using namespace std;
vector<int> first_last_ind(vector<int>&nums,int x){
    int n=nums.size();
   
    int first=INT_MAX;
    int last=INT_MIN;
    
    //assume the array is already sorted
    for(int i=0;i<n;i++){
        //fist occurrence loop
        if(nums[i]==x) first=min(first,i);

        //last occurrence loop
        if(nums[i]==x) last=max(last,i);
    }

    if(first==INT_MAX && last==INT_MIN) first=-1,last=-1;
    
    vector<int>ans{first,last};
    return ans;
    
    }

int main(){
    vector<int>nums={5,7,7,8,8,10};
    int x=6;
    //vector<int>nums={};
    //int x=0;
    vector<int>ans=first_last_ind(nums,x);
    cout<<"The first occurence of "<<x<<" is : "<<ans[0]<<endl;
    cout<<"The last occurrence of "<<x<<" is : "<<ans[1]<<endl;
    return 0;
}

//Time Complexity : O(N) where N is the size of given array, as linear search is used for searching the index.
//Space Complexity : O(1) const space is required for variables and 2 element vector.