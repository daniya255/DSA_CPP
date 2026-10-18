#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0); // Initialize answer array with 0s
        stack<int> st;            
        
        for (int i = 0; i < n; i++) {
            // While the stack isn't empty and today's temp is warmer 
            // than the temperature at the index stored at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                
                // The wait time is the difference between current day and the previous day
                answer[prevIndex] = i - prevIndex;
            }
            
            // Push the current day's index onto the stack
            st.push(i);
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl; 
    // Expected Output: [1, 1, 4, 2, 1, 1, 0, 0]
    
    return 0;
}