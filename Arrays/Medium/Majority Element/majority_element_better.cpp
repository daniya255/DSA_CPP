#include<bits/stdc++.h>
using namespace std;
int majority_element(vector<int>&nums){
    int n=nums.size();
   unordered_map<int,int>hash;

   //iterating over the vector for hashing the element in the map (element,value)
   for(int i=0;i<n;i++) hash[nums[i]]++;

   //iterating over the map to find majority element
   for(auto it: hash){
    if(it.second>(n/2)) return it.first;
   }

    // Return -1 if no majority element is found
    return -1;
}

int main(){
    vector<int>nums={2,2,3,1,4,2,2};
    cout<<"Majority element : "<<majority_element(nums);
    return 0;
}


// Time Complexity: O(N), where N is the size of the input array. This is because we are using a for loop for hashing and a for loop for finding majority element
//Total Time Complexity : O(N) + O(N) = O(N) because we use unordered map
//If data is very complex and there maybe chances of worst case then we switch to ordered map with time complexity : O(N logN)

// Space Complexity: O(N) worst case if all elements are unique

