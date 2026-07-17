#include<iostream>
#include<vector>
using namespace std;
int number_appearing_once(vector<int>&nums){
    int n=nums.size();  
    for(int i=0;i<n;i++){
        int num=nums[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==num) count++;
        }
        if(count==1) {
            return num;
        }
    }
    return -1;
}
int main(){
    vector<int>nums={1,1,2,2,3,4,4,5,5};
    cout<<number_appearing_once(nums);
    return 0;
}

//Time Complexity : O(n*n) where n is the size of the input vector
//Space Complexity : O(1) extra space for variables like 'n', 'count' and 'nums'
