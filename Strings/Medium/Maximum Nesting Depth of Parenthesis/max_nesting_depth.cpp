#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{

    if (s.empty())
        return 0;

    int depth = 0;
    int max_depth = -1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            depth++;
        if (s[i] == ')')
            depth--;

        max_depth = max(max_depth, depth);
    }

    return max_depth;
}

int main()
{
    string s = "()(())((()()))";

    cout << "The depth of nested parenthese is : " << maxDepth(s) << endl;
    return 0;
}

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as only constant extra space is used.
