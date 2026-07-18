#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> three_sum(vector<int>&nums,int target){
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1])continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    vector<int>temp{nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum>target) {
                    l--;
                }
                else k++;
            }
           
        }
    }
    return ans;
}
int main(){
    vector<int>nums={1,1,4,2,3,3,6,2};
    int target=8;
    vector<vector<int>>result=three_sum(nums,target);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*Time Complexity: O(N3), as Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 
Space Complexity: O(no. of quadruplets), as This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/