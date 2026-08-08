#include <bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int n = s.length();
    int sum = 0;

        // Loop over all substrings
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;

        for (int j = i; j < n; j++) {
            // Increase frequency of current character
            freq[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            // Find max and min frequency
            for (auto it : freq) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }

            // Add difference to sum
            sum += (maxi - mini);
        }
    }

    return sum;
}

int main() {
    string s = "aabcb";
    cout << "Beauty Sum: " << beautySum(s) << endl;
    return 0;
}

//Time Complexity:
// Outer loop: O(n) (for each starting index)
// Inner loop: O(n) (for each ending index)
// Computing max and min for frequencies: O(26) in the worst case (since only lowercase letters), O(n^2 * 26) ≈ O(n^2) because 26 is constant.

// Space Complexity:
// Frequency map uses at most 26 characters → O(26) = O(1).
// No extra data structures apart from that.
