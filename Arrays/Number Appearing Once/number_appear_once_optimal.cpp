#include<iostream>
#include<vector>
#include<map>
using namespace std;
int number_appearing_once(vector<int>&nums){
    int n=nums.size();
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1^=nums[i];
    }

    return xor1;
   
}
int main(){
    vector<int>nums={1,1,2,2,3,4,4,5,5};
    cout<<number_appearing_once(nums);
    return 0;
}

//Time Complexity : O(n) where n is the size of the input vector
//Space Complexiy : O(1) extra space for variable xor1.