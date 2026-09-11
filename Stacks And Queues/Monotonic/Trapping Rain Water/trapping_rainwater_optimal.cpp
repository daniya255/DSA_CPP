#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int volume = 0;

    while (left < right) {
        //left is smaller or equals to right
        if (height[left] <= height[right]) {
            //found a new higher boundary
            if (height[left] >= leftMax) {
                leftMax = height[left];
            }
            //leftmax is the higher boundary 
            else {
                volume += (leftMax - height[left]);
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                volume += (rightMax - height[right]);
            }
            right--;
        }
    }

    return volume;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Rainwater: " << trap(height) << endl;
    return 0;
}

//ime Complexity: O(n) because the two pointers traverse the array only once, each pointer moving inward and covering the entire array in total linear time.
//Space Complexity: O(1) as only constant extra space is used for pointers and variables, regardless of input size.