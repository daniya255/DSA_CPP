#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> three_sum(vector<int>&nums){
    set<vector<int>>st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        set<int>hashset;
        for(int j=i+1;j<n;j++){
            int k= -(nums[i]+nums[j]);
            if(hashset.find(k)!=hashset.end()){
                vector<int>temp={nums[i],nums[j],k};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>>ans(st.begin(),st.end());
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

//Time Complexity: O(N2 * log(no. of unique triplets)), as we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.


