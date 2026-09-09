#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int>result;
    for(int i = 0; i < nums1.size(); i++) {
        int target = nums1[i];
        bool found = false;
        
        for(int j = 0; j < nums2.size(); j++) {
            if (nums2[j] == target) {
                // Scan to the right in nums2, NOT nums1
                for(int k = j + 1; k < nums2.size(); k++) {
                    if (target < nums2[k]) {
                        result.push_back(nums2[k]);
                        found = true;
                        break;
                    }
                }
                break; // Found our element in nums2, no need to keep searching nums2
            }
        }
        
        // If we finished scanning nums2 to the right and found nothing larger
        if (!found) {
            result.push_back(-1);
        }
    }
    
    return result;
}

int main(){
    vector<int>nums1={2,1,4};
    vector<int>nums2={1,2,3,4};
    vector<int>result=nextGreaterElement(nums1,nums2);
    for(int el : nums1) {
        cout<<el<<" ";
    }
    cout<<endl;
    for(int num: result){
        cout<<num<<" ";
    }
    return 0;
}

//Time Complexity: O(N * M) where N is the size of nums1 and M is the size of nums2
//Space Complexity: O(1) auxiliary space (ignoring the output vector), because no extra data structures like stacks or hash maps are used.