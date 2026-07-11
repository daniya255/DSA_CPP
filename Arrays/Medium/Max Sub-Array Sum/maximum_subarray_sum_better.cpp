#include<bits/stdc++.h>
using namespace std;
int max_subarray_sum(vector<int>&nums){
    int n=nums.size();
    int maxlen=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
           sum+=nums[j];
            maxlen=max(maxlen,sum);
        }
    }

    return maxlen;
}
int main(){
    vector<int>nums={2,-2,1,-4,6,-5,10,2};
    cout<<"Max Sum : "<<max_subarray_sum(nums);
    return 0;
}


// Time Complexity: O(N^2), where N is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index of the subarray.

//Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.