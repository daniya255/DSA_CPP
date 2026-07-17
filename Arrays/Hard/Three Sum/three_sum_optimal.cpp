#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> three_sum(vector<int>&nums){
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum>0){
                k--;
            }
            else if (sum<0) {
                j++;
            }
            else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                 while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
        
            }
           }
    }

    return ans;
}
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>result=three_sum(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//Time Complexity:  O(N log N) + O(N*N) = O(N^2)
//O(N*N) for nested loops and O(NlogN) for sorting the vector
//Space Complexity : O(1) const space for variables and o(m) where m is the number of unique triplet found.
//It can also be considered O(1) as temp only stores three numbers.

