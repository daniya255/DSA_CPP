#include<bits/stdc++.h>
using namespace std;
int sumMins(vector<int>&nums){
    int n=nums.size();

    vector<int>left(n),right(n);
    stack<int>st;

    long long totalSum = 0;
    int MOD = 1e9 + 7;

    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        left[i]= (st.empty()) ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        right[i]= st.empty() ? n : st.top();
        st.push(i);
    }

    for(int i=0; i<n; i++){
        long long leftCount= i - left[i];
        long long rightCount= right[i] - i;
        long long contribution = (nums[i] * leftCount % MOD) * rightCount % MOD;
        totalSum = (totalSum + contribution) % MOD;
    }

    return totalSum;
}
int main(){
    vector<int>nums={3,1,2,4};
    int result=sumMins(nums);
    cout<<result<<endl;
    return 0;
}

//Time Complexity: O(N), since finding the indices of next smaller elements and previous smaller elements take O(2*N) time each and calculating the sum of subarrays minimum takes O(N) time.
//Space Complexity: O(N), since finding the indices of the next smaller elements and previous smaller elements takes O(N) space each due to stack space and storing the indices of the next smaller elements and previous smaller elements takes O(N) space each.