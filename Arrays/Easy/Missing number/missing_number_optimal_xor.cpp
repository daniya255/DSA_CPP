#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>&nums,int N){
    int n=N-1;
    int xor1=0,xor2=0;

    //xor of the elements of the vector
    for(int i=0;i<n;i++) xor1^=nums[i];

    //xor of the n natural numbers
    for(int i=1;i<=N;i++) xor2^=i;

    //returns the missing number
    return xor2^xor1;

}
int main(){
    vector<int>nums={1,2,3,4,6};
    int N=6;
    cout<<missingNumber(nums,N);
    return 0;
}

//Time Complexity : O(n) where n is the number of elements in the input vector `nums`. This is because we iterate through the vector once to calculate the sum of its elements and then iterate from 1 to N to calculate the expected sum.  
//Space Complexity : O(1) as we are using a constant amount of extra space for the variables `xor1`, `xor2`, `n`.