class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            char curr = num[i];

            while (k > 0 && !st.empty() && st.top() > curr) {
                st.pop();
                k--;
            }
            st.push(curr);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        while (result.size() > 0 && result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end());

        if (result.empty())
            return "0";

        return result;
    }
};