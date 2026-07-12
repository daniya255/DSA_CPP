#include<bits/stdc++.h>
using namespace std;
    
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

int main(){
    vector<int>nums={3,2,1,4,5};
    nextPermutation(nums);
    for(int i:nums) cout<<i<<" ";
    cout<<endl;
    return 0;
}

//Time Complexity: O(N)
//Space Complexity: O(1)
