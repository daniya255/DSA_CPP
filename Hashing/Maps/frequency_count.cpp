#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<vector<int>>result;
        for( auto it : mp){
            result.push_back({it.first,it.second});
        }
        return result;
    }
};
int main(){

   vector<int>arr={1,2,1,2,3,4,5};
   Solution s;
   vector<vector<int>>result;
   result=s.countFrequencies(arr);

    return 0;

}