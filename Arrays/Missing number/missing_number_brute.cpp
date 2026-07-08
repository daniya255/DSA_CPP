#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>&nums,int N){
    int n=N-1;
    bool flag;
   for(int i=1;i<=N;i++){
     flag=false;
    for(int j=0;j<n;j++){
        if(i==nums[j]){
            flag=true;
            break;
        }
    }
    if(flag==false) return i;
}
    return -1;
}

int main(){
    vector<int>nums={1,2,3,4,6};
    int N=6;
    cout<<missingNumber(nums,N);
    return 0;
}

//Time Complexity : O(n*N) where n is the number of elements in the input vector `nums`. This is because we have a nested loop where the outer loop runs from 1 to N and the inner loop iterates through the vector `nums` to check for the presence of each number.
//Space Complexity : O(1) as we are using a constant amount of extra space for the variables `flag`, `i`, and `j`.