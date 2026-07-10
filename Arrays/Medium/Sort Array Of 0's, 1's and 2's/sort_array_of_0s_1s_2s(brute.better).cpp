#include <bits/stdc++.h>
using namespace std;
void sort_array(vector<int>&nums){
    int n=nums.size();
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) count0++;
        else if(nums[i]==1) count1++;
        else count2++;
    }

    for(int i=0;i<count0;i++){
        nums[i]=0;
    }

    for(int i=count0;i<count1+count0;i++){
        nums[i]=1;
    }

    for(int i=count0+count1;i<n;i++){
        nums[i]=2;
    }
}

int main(){
    vector<int>nums={0,1,1,2,1,1,0,2,1,0,1,1,2};
    sort_array(nums);
    for(int val:nums){
        cout<<val<<" ";
    }
    return 0;
}

//Time Complexity: O(n),We traverse the array twice: once to count, once to overwrite. Each operation is O(n).

//Space Complexity: O(1), We use only a constant number of counters regardless of the input size. No extra array is used.