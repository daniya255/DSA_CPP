#include<bits/stdc++.h>
using namespace std;
int majority_element(vector<int>&nums){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j]) count++;
        }
        // Check if frequency of nums[i] is greater than n/2
        if(count>int(n/2)) return nums[i];
    }
 // Return -1 if no majority element is found
    return -1;
}

int main(){
    vector<int>nums={2,2,3,1,4,2,2};
    cout<<"Majority element : "<<majority_element(nums);
    return 0;
}


// Time Complexity: O(N^2), where N is the size of the input array. This is because we are using a nested loop to count the occurrences of each element.

// Space Complexity: O(1), as we are using a constant amount of space for the counters and indices.

