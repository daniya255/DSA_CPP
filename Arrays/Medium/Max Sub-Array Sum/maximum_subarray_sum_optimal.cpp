
//          Kadane's Algorithm

// 1.Iterate through the array using a variable i. During each iteration, add the current element arr[i] to a running sum variable.
// 2.Keep track of the maximum sum encountered during the iteration by comparing the current sum with the previous maximum sum, and update it if the current sum is greater.
// 3.If at any point the sum becomes negative, reset it to 0, as a negative sum won't contribute positively to the overall maximum sum.
// 4.Continue the iteration until all elements in the array are processed.
// 5.Finally, return the maximum sum encountered during the iteration.


#include<bits/stdc++.h>
using namespace std;
int max_subarray_sum(vector<int>&nums){
    int n=nums.size();
    int maxlen=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        maxlen=max(maxlen,sum);
        if(sum<0) sum=0;

    }
    if(maxlen<0) maxlen=0;
        return maxlen;
}
int main(){
    vector<int>nums={-2,-2,-1,-4};
    cout<<"Max Sum : "<<max_subarray_sum(nums);
    return 0;
}


// Time Complexity: O(N), where N is the size of the array. 

// Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.