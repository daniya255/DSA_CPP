#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> three_sum(vector<int>&nums,int target){
    set<vector<int>>st;
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target) {
                        vector<int>temp{nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
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

//Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
// Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.

