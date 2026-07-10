class Solution {
public:
    int majorityElement(vector<int>& nums) {
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
};