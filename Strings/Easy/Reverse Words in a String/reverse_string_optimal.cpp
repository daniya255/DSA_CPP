#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{

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

    for (int i = end; i >= start; i--)
    {

        if (s[i] != ' ')
            reversed += s[i];

        if (s[i] == ' ' || i == start)
        {

            if (!reversed.empty())
                reverse(reversed.begin(), reversed.end());

            if (result.empty())
            {
                result = reversed;
            }
            else
            {
                result += " " + reversed;
            }

            reversed = "";

            while (i > start && s[i - 1] == ' ')
                i--;
        }
    }

    return result;
}
int main()
{
    string s = " amazing coding skills ";
    cout << reverseWords(s) << endl;
    return 0;
}

/*
Time Complexity: O(N) 
-->Trimming spaces: The two while loops at the beginning scan from both ends towards the center, taking at most O(N) time.
-->Main loop: The for loop iterates backwards through the string once from end down to start, meaning every character is visited. Reversing the reversed string takes time proportional to the length of that individual word.
-->Overall: Because each character is processed a constant number of times across the entire string length N, the total time complexity is linear: O(N).

Space Complexity: O(N)
-->Auxiliary variables: You are using standard integer pointers (start, end, i) which take O(1) space.
-->Result & temporary strings: The result string stores the final reversed sentence (up to $N$ characters), and reversed temporarily holds individual words.
-->Overall: To store the newly constructed output string of size up to N, the auxiliary space complexity is O(N)

*/