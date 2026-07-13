#include<bits/stdc++.h>
using namespace std;
int max_sequence(vector<int>&nums){
    int n=nums.size();

    // If the array is empty
    if(n==0) return 0;

    int longest=0,count=0;

    unordered_set<int>st;

    // Put all the array elements into the set
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }

    /* Traverse the set to find the longest sequence  */
    for(auto it : st){

        // Check if 'it' is a starting number of a sequence
        if(st.find(it-1)==st.end()){
            count=1;
            int x=it;
            // Find consecutive numbers in the set
            while(st.find(x+1)!=st.end()){
                x++;
                count++;
            }
        }

        longest=max(longest,count);

    }
       
    
    return longest;
}
int main(){
    vector<int>nums={1,4,101,43,3,100,2,5,102};
    cout<<max_sequence(nums);
    return 0;
}

// Time Complexity: O(n), where n is the number of elements in the array. This is because we traverse each element once to build the set and then again to find the longest consecutive sequence.

// Space Complexity: O(n), as we use a set to store the unique elements of the array, which in the worst case can be equal to the size of the input array.

