#include<bits/stdc++.h>
using namespace std;
int max_sequence(vector<int>&nums){
    int n=nums.size();
    if(n==0) return 0;
    int longest=0,count=0;
    int second_small=INT_MIN;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(nums[i]-1==second_small){
            count+=1;
            second_small=nums[i];
        }
        else if(second_small!=nums[i]){
            count=1;
            second_small=nums[i];
        }
        longest=max(longest,count);
        }
    
    return longest;
}
int main(){
    vector<int>nums={1,4,101,43,3,100,2,5,102};
    cout<<max_sequence(nums);
    return 0;
}

// Time Complexity: O(n log n), where n is the number of elements in the array. This is due to the sorting step, which is the most time-consuming operation in this approach.
//total time complexity : O(n) + O(nlogn) = O(n)
// Space Complexity: O(1), as we are using only a constant amount of extra space.