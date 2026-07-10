#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>two_sum(vector<int>&nums,int target){
    int n=nums.size();
      vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({nums[i], i});
        }
    sort(numsWithIndex.begin(), numsWithIndex.end());

    int right=n-1,left=0;

    while(left<right){
        int sum=numsWithIndex[right].first+numsWithIndex[left].first;
        if(sum==target) return {numsWithIndex[left].second,numsWithIndex[right].second};
        else if (sum>target) right--;
        else left++;
    }
    return {0};
}
int main(){
    vector<int>nums={1,2,5,2,7,8,5};
    vector<int>result=two_sum(nums,8);
    for(int val:result){
        cout<<val<<" ";
    }
    
    return 0;
}

//Time Complexity : O(nlog n) where n is size of the input vector
//Building the pair vector: Looping through the input array once to pair each number with its index takes O(n) time.
//Sorting: Sorting the numsWithIndex vector of size n takes O(n log n) time
//The while loop moves the left and right pointers inward. In the worst case, they cross each other after visiting every element exactly once, taking O(n) time.
//Combining these together:{Total Time} = O(n) + O(n log n) + O(n) = O(n log n)

//Space Complexity : O(n) because of sorted vector of length n