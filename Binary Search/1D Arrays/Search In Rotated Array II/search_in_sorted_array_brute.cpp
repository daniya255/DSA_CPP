#include<bits/stdc++.h>
using namespace std;
int rotated_search(vector<int>& arr, int n, int x) {
    
    for (int i = 0; i < n; i++) {
        
        if (arr[i]==x) return true;

    }
    return false;
}

int main()
{
    vector<int> nums =  {2,5,6,0,0,1,2};
    int x=3;
    bool ans = rotated_search(nums, nums.size(),x);
    cout << ans << "\n";
    return 0;
}

//Time Complexity : O(N) linear search
//Space Complexity : O(1) const space required