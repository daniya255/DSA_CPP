#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int number_appearing_once(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>hash;

    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }

    for(auto it : hash){
        if(it.second==1)
            return it.first;
    }

    return -1;
   
}
int main(){
    vector<int>nums={1,1,2,2,3,4,4,5,5};
    cout<<number_appearing_once(nums);
    return 0;
}

//Time Complexity :
// O(1) for avg/base case (unordered map) and O(M) for worst , where M is the number of elements in the map
//Total time : O(n) for 1st loop and O(M) for second loop 
//So total time complexity : O(n) where n is the size of the input vector

//Space Complexity : O(n/2 + 1) where n is the size of the input vector
