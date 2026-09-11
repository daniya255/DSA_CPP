class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2)
            return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int volume = 0;

        while (left < right) {
            // left is smaller or equals to right
            if (height[left] <= height[right]) {
                // found a new higher boundary
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                // leftmax is the higher boundary
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
};