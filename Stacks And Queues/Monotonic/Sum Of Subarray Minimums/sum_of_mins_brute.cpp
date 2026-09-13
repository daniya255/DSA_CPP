#include<bits\stdc++.h>
using namespace std;
int sum_min(vector<int>&nums){
    int mod=1e9 + 7;
    int sum=0;

    for(int i=0;i<nums.size();i++){
        int mini=nums[i];
        for(int j=i;j<nums.size();j++){
            mini=min(mini,nums[j]);
            sum=(sum+mini) % mod;
        }
    }

    return sum;
}
int main(){
    vector<int>nums={3,2,1,4};
    int sum=sum_min(nums);
    cout<<sum<<endl;
    return 0;
}

//Time Complexity: O(N²), since we are using two nested loops.
//Space Complexity: O(1), as we are not using any extra space except for the input array and a few variables.