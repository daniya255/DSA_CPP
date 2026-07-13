#include<bits/stdc++.h>
using namespace std;
bool linear_search(vector<int>&nums,int x){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==x) return true;
    }
    return false;

}
int max_sequence(vector<int>&nums){
    int n=nums.size();
    if(n==0) return 0;
    int longest=0,count=0;
    for(int i=0;i<n;i++){
        int x=nums[i];
        count=1;
        while(linear_search(nums,x+1)==true){
                count++;
                x++;
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

//Time Complexity : O(N*N*N) , where N is the size of the input array.
//TOTAL TIME COMPLEXITY = INNER(N) * MIDDLE(N) * OUTER(N)
//Space Complexity : O(1) beacuse no extra data structure required.