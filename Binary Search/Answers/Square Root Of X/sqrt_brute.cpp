#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find square root 
    int findSqrt(int n) {
        int sqrt=0;
        
        // Traverse the array
        for (int i = 0; i < n/2; i++) {
            if(i*i<=n) sqrt=i;
        }

        return sqrt;
    }
};

// Driver
int main() {
    Solution sol;
    int n=28;
    int sqrt = sol.findSqrt(n);
    cout << "The square root of "<<n<<" is : "<<sqrt<<endl;
    return 0;
}

//Time Complexity: O(N/2)
//Space Complexity: O(1), constant additional space is used.