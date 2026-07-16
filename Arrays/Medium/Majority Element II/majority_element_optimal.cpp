#include<bits/stdc++.h>
using namespace std;
vector<int>majority_element(vector<int>&nums){
    int n=nums.size();
    int count1=0,count2=0;
    int e1=INT_MIN,e2=INT_MIN;
    vector<int>result;
    for(int i=0;i<n;i++){
        if(count1==0 && nums[i]!=e2){
            count1=1;
            e1=nums[i];
        }
        else if(count2==0 && nums[i]!=e1){
            count2=1;
            e2=nums[i];
        }
        else if (nums[i]==e1) count1++;
        else if(nums[i]==e2) count2++;
        else count1--,count2--;
           
    }
    count1=0;count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==e1) count1++;
        else if(nums[i]==e2) count2++;
    }
    if(count1>(n/3)) result.push_back(e1);
    if(count2>(n/3)) result.push_back(e2);
    sort(result.begin(),result.end());
    return result;
}
int main(){
    vector<int>nums={1,4,5,1,2,1,2,2};
    vector<int>result=majority_element(nums);
    for(int val:result) cout<<val<<endl;
    return 0;
}

//Time Complexity: O(N), where N is the size of the input array. We traverse the array twice: once to find potential candidates and once to validate them.
//Space Complexity: O(1), as we are using a constant amount of space for the counters and candidate elements, regardless of the input size.

