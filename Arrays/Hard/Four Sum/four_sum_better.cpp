#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> three_sum(vector<int>&nums,int target){
    set<vector<int>>st;
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int>hashset;
            for(int k=j+1;k<n;k++){
                int l=target-(nums[i]+nums[j]+nums[k]);
                if(hashset.find(l)!=hashset.end()){
                    vector<int>temp{nums[i],nums[j],nums[k],l};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
                
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

/*Time Complexity: O(N3*log(M)), as we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.
Space Complexity: O(2 * no. of the quadruplets)+O(N), as we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).
*/