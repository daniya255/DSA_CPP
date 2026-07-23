#include<bits/stdc++.h>
using namespace std;
int min_search(vector<int>& nums, int n) {

    int mini=INT_MAX;
    
    for (int i = 0; i < n; i++) {
        
        if (nums[i]<mini) mini=nums[i];

    }
    return mini;
}

int main()
{
    vector<int> nums =  {2,5,6,0,0,1,2};
    int ans = min_search(nums, nums.size());
    cout <<"The minimum element is : "<< ans << "\n";
    return 0;
}

//Time Complexity : O(N) linear search
//Space Complexity : O(1) const space required