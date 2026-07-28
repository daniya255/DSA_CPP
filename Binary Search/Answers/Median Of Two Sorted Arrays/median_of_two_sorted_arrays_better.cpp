#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    int i=0,j=0;
    int n=n1+n2;
    int ind2=n/2;
    int ind1=ind2-1;
    int el1=-1,el2=-1;
    int count=0;

     while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(count==ind1) el1=nums1[i];
            if(count==ind2) el2=nums1[i];
            i++;
           
        }
        else{
            if(count==ind1) el1=nums2[j];
            if(count==ind2) el2=nums2[j];
            j++;
           
        }
        count++;
    }

    while(i<n1){
        if(count==ind1) el1=nums1[i];
        if(count==ind2) el2=nums1[i];
        i++;
        count++;     

        }
   
    while(j<n2){
        if(count==ind1) el1=nums2[j];
        if(count==ind2) el2=nums2[j];
        j++;
        count++;    
    }

    if(n%2==1) return el2;

    return double(double(el1+el2))/2.0;

}
int main(){
    vector<int>nums1={1,2};
    vector<int>nums2={3,4};
    cout<<"The median of the two sorted arrays is : "<<findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}

//Time Complexity: O(n1 + n2) — You still traverse through elements up to the middle index.
//Space Complexity: O(1) — No extra arrays or vectors are created; you only use a few integer variables (ind1, ind2, el1, el2, count).
