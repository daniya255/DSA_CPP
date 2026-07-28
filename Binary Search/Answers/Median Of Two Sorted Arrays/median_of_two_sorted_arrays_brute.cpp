#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){

    vector<int>nums3;
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;

    int i=0,j=0;
    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            nums3.push_back(nums1[i++]);
           
        }
        else if(nums2[j]<nums1[i]){
            nums3.push_back(nums2[j++]);
        }
        else{
            nums3.push_back(nums1[i++]);
            nums3.push_back(nums2[j++]);
        }
    }

    while(i<n1){
        nums3.push_back(nums1[i++]);
        }
   
    while(j<n2){
        nums3.push_back(nums2[j++]);
        }
    
    if(n%2==1) return nums3[n/2];
    
    double m1=nums3[n/2];
    double m2=m1-1;

    return double(m1+m2)/2.0;

}

int main(){
    vector<int>nums1={1,2};
    vector<int>nums2={3,4};
    cout<<"The median of the two sorted arrays is : "<<findMedianSortedArrays(nums1,nums2)<<endl;
   
    return 0;
}

//Time Complexity: O(n1 + n2) — You traverse both arrays completely during the merge step.
//Space Complexity: O(n1 + n2) — You store all elements combined into a brand new vector nums3