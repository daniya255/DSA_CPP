class Solution {
public:
    int maxDepth(string s) {
        if (s.empty())
            return 0;

        int depth = 0;
        int max_depth = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                depth++;
            if (s[i] == ')')
                depth--;

            max_depth = max(max_depth, depth);
        }

        return max_depth;
    }
};