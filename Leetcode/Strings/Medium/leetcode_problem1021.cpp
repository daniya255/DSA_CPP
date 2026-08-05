class Solution {
public:
    string removeOuterParentheses(string s) {
        if (s.size() == 1)
            return "";
        if (s.empty())
            return "";

        if (s.size() % 2 == 1)
            return "";

        int balance = 0;
        string result = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                if (balance > 0)
                    result += s[i];
                balance++;
            }
            if (s[i] == ')') {
                balance--;
                if (balance > 0)
                    result += s[i];
            }
        }

        return result;
    }
};