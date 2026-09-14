#include<bits/stdc++.h>
using namespace std;
int sumMins(vector<int>&nums){
    int n=nums.size();

    vector<int>left(n),right(n);
    stack<int>st;

    long long totalSum = 0;
    int MOD = 1e9 + 7;

    //finding PSE(Previous Smaller Element)
    for(int i=0;i<n;i++){
        //uisng stack to check if there is a smaller element before or not
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        //check if current is smallest or an other element before it
        left[i]= (st.empty()) ? -1 : st.top();
        st.push(i);
    }

    //emptying stack for NSE
    while(!st.empty()) st.pop();

    //finding NSE from right to left
    for(int i=n-1;i>=0;i--){
        //checking for NSE by comparing current element with the elements in stack
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        //check if there is a NSE or not, if not the current element can stretch till end
        right[i]= st.empty() ? n : st.top();
        st.push(i);
    }

    for(int i=0; i<n; i++){
        //finding left boundary
        long long leftCount= i - left[i];
        //finding right boundary
        long long rightCount= right[i] - i;
        //finding total subarrays and multiplying them to the value
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
