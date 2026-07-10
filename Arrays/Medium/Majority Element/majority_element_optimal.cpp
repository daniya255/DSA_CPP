//      Moore's Voting Algorithm

//1. Initialize two variables: count to track the count of elements, and element to keep track of the element being counted.
//2. Traverse through the given array. If count is 0, store the current value of the array as element.
//3. If the current element in the array is the same as element, increment the count by 1.
//4. If the current element is different from element, decrement the count by 1.
//5. At the end of the traversal, the integer stored in element will be the expected result (the majority element).


#include<bits/stdc++.h>
using namespace std;
int majority_element(vector<int>&nums){
    int n=nums.size();
    int count=0;
    int el;

    //Applying the moore's voting algo
    for(int i=0;i<n;i++){
       if(count==0){
        count++;
        el=nums[i];
       }
       else if(nums[i]==el) count++;
       else count--;
    }

     
    /* Checking if the stored element
    is the majority element*/
    int count1=0;
    for(int i=0;i<n;i++){
        if(el==nums[i]) count1++;
        if(count1>(n/2)) return nums[i];
    }
 // Return -1 if no majority element is found
    return -1;
}

int main(){
    vector<int>nums={2,2,3,1,4,2,2};
    cout<<"Majority element : "<<majority_element(nums);
    return 0;
}


// Time Complexity: O(N), where N is the size of the input array. This is because we are iterating through the array once to find the potential majority element and then again to verify it.
// Space Complexity: O(1), as we are using a constant amount of space for the counters and indices.

