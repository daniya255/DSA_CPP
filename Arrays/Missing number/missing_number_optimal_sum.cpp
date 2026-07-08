#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>&nums,int N){
    int n=N-1;
    long sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        sum1+=nums[i];
    }

    sum2=N*(N+1)/2;

    return sum2-sum1;
}
int main(){
    vector<int>nums={1,2,3,4,6};
    int N=6;
    cout<<missingNumber(nums,N);
    return 0;
}

//Time Complexity : O(n) where n is the number of elements in the input vector `nums`. This is because we iterate through the vector once to calculate the sum of its elements and then iterate from 1 to N to calculate the expected sum.  
//Space Complexity : O(1) as we are using a constant amount of extra space for the variables `sum1`, `sum2`, and `n`.