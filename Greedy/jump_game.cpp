#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
    int farthest=0;
    int n=nums.size();

    for(int i=0; i<n; i++){
        if(farthest < i) return false;
        farthest = max(farthest,i+nums[i]);
        if (farthest >= n-1) return true;

    }

    return true;
}

int main(){
    vector<int>nums = {3,2,1,0,4};
    bool isPossible = canJump(nums);
    cout <<((isPossible) ? "The last index can be reached" : "The last index can't be reached")<<endl ;
    return 0;
}

//Time Complexity: O(n), because the array is scanned once.
//Space Complexity: O(1), because constant space is used.

