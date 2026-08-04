class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";

        int start = 0, end = s.size() - 1;
        string result = "", reversed = "";

        while (start <= end && s[start] == ' ')
            start++;
        while (end >= start && s[end] == ' ')
            end--;

        if (start > end)
            return "";

        for (int i = end; i >= start; i--) {

            if (s[i] != ' ')
                reversed += s[i];

            if (s[i] == ' ' || i == start) {

                if (!reversed.empty())
                    reverse(reversed.begin(), reversed.end());

                if (result.empty()) {
                    result = reversed;
                } else {
                    result += " " + reversed;
                }

                reversed = "";

                while (i > start && s[i - 1] == ' ')
                    i--;
            }
        }

        return result;
    }
};