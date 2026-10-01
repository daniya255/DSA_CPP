#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>result;
    deque<int> window ;
    if (nums.empty() || k==0) return result;
    for(int i=0; i<nums.size(); i++){
        if(!window.empty() && window.front() <= i-k) window.pop_front();

        while(!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();

        window.push_back(i);  

        if (i>= k-1) result.push_back(nums[window.front()]);
    }
    
    return result;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>result = maxSlidingWindow(nums,k);
    for(int i: result) cout<<i<<" ";

    return 0;
}

//Time Complexity: O(n) ; even though there is a while loop inside for loop, but every element is popped and pushed on the queue atmost once
//Space Complexity : O(K) auxiliary space ; dequeue store only indices, in worst case it stores k indices