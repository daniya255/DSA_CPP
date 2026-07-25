class Solution {
public:
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
};