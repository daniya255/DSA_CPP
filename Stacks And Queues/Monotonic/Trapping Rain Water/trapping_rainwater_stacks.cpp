#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int volume = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // While current bar is taller than the bar at the stack's top,
        // we have found a right boundary for a trapped pocket of water.
        while (!st.empty() && height[i] > height[st.top()]) {
            int bottom = st.top();
            st.pop();

            // If there's no left boundary in the stack, water spills out the side
            if (st.empty()) {
                break;
            }

            int left = st.top();
            
            // Calculate width and height of the horizontal water layer
            int width = i - left - 1;
            int boundedHeight = min(height[left], height[i]) - height[bottom];
            
            volume += width*boundedHeight;
        }
        
        // Push the current index onto the stack
        st.push(i);
    }

    return volume;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Rainwater (Stack): " << trap(height) << endl;
    return 0;
}

//Time Complexity: O(N)
//Space Complexity: O(N)