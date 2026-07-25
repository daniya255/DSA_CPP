#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if bouquets can be made or not
    int calculateTotalDays(vector<int>& blooms, int d,int m,int k) {
        int count=0;
        int bouquets=0;
        for (int bloom: blooms) {

           if(bloom<=d) {
            count++;
            if(count==k){
            bouquets++;
            count=0; 
           }

        }

        else count=0;
    }

    return bouquets>=m;
}

    // Function to find minimum eating speed
    int minDays(vector<int>& blooms, int m, int k) {
        // Check the impossible condition first
        if(blooms.size()<(m*k)) return -1;

        //lowest and highest values for days
        int high = *max_element(blooms.begin(), blooms.end());
        int low=*min_element(blooms.begin(),blooms.end());

        // Try every possible day between low and high
        for (int i = low; i <= high; i++) {
            int possible = calculateTotalDays(blooms,i,m,k);
            if (possible) return i;
        }
        
        return -1;
    }
};

int main() {
    // Input array
    vector<int> blooms = {1,10,3,10,2};
    int m=3, k=1;

    Solution obj;
    cout << obj.minDays(blooms,m,k);
    return 0;
}

// Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
//Space Complexity : O(1) as we are not using any extra space to solve this problem.
