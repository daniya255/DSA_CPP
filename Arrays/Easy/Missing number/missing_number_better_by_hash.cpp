#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>&nums,int N){
    int n=N-1;
    int hash[N+1]={0};
   for(int i=0;i<n;i++){
        hash[nums[i]]=1;
    }

    for(int i=1;i<N;i++){
        if(hash[i]==0) return i;
    }

    return -1;

    
}

int main(){
    vector<int>nums={1,2,3,4,6};
    int N=6;
    cout<<missingNumber(nums,N);
    return 0;
}

//Time Complexity : O(n+N) where n is the number of elements in the input vector `nums`. This is because we iterate through the vector once to fill the hash array and then iterate from 1 to N to check for the missing number.
//Space Complexity : O(N) as we are using an extra array of size N+1 to store the presence of numbers in the input vector `nums`.