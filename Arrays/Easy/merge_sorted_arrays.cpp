#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1;
    int p2 = n-1;
    int p = m+n-1;

    while (p2>=0){
        if (p1>=0 && nums1[p1] > nums2[p2]){
            nums1[p--] = nums1[p1--];
        }
        else{
            nums1[p--] = nums2[p2--];
        }
    }
}

int main(){
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    merge(nums1,3,nums2,3);
    for (int i: nums1){
        cout<<i<<" ";
    }
    return 0;
}

//Time Complexity: O(m + n) because it touches each element at most once.
S//pace Complexity: O(1) because everything is done in-place inside nums1.