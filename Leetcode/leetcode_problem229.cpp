class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
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
};