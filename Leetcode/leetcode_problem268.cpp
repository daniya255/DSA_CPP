class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int N = nums.size();
    int n=N-1;
    int xor1=0,xor2=0;

    //xor of the elements of the vector
    for(int i=0;i<=n;i++) xor1^=nums[i];

    //xor of the n natural numbers
    for(int i=0;i<=N;i++) xor2^=i;

    //returns the missing number
    return xor2^xor1;

    }
};