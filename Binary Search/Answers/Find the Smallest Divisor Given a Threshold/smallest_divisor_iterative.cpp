#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&nums,int mid,int threshold){
    long long sum=0;
    for(int  num: nums){
        sum+=ceil((double)num/(double)mid);
    }

    return sum<=threshold;
}

int smallestDivisor(vector<int>&nums,int threshold){
    
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int possible_ans=0;

    while(low<=high){
        int mid=(low+high)/2;

        bool check=isPossible(nums,mid,threshold);

        if(check){
            possible_ans=mid;
            high=mid-1;
        }
        else low=mid+1;

    }

    return possible_ans;
}
int main(){
    vector<int> nums = {44,22,33,11,1};
    int  threshold = 5;
    int ans=smallestDivisor(nums,threshold);
    cout<<"The smallest divisor is : "<<ans<<endl;
    return 0;
}

//Time Complexity:O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array. We are applying binary search on our answers that are in the range of [1, max(arr[])]. For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).
//Space Complexity: O(1), no extra space is used.