#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    if (s.empty())
        return true;
    if (s.size() == 1)
        return false;

    stack<char> ch;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            ch.push(s[i]);
        }
        else
        {
            if (ch.empty())
                return false;

            char last = ch.top();
            ch.pop();

            if ((last == '(' && s[i] == ')') || (last == '{' && s[i] == '}') || (last == '[' && s[i] == ']'))
                continue;
            else
                return false;
        }
    }

    return ch.empty();
}
int main()
{
    string s = "[{()}]";
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}

// Time Complexity: O(n). Single for loop used
// Space Complexity: O(N). Stack space
