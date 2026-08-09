class Solution {
public:
    // Helper function that expands outward as far as characters match
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the valid palindrome found
        return right - left - 1;
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0; // Tracks the starting index of the longest palindrome
    int maxLength = 0; // Tracks the length of the longest palindrome

    for (int i = 0; i < s.size(); i++) {
        // Case 1: Odd length palindrome (center is at character i)
        int len1 = expandAroundCenter(s, i, i);
            
        // Case 2: Even length palindrome (center is in the gap between i and i + 1)
        int len2 = expandAroundCenter(s, i, i + 1);

        // Find the maximum length between the two cases
        int currentMax = max(len1, len2);

        // If we found a longer palindrome, update our tracker
        if (currentMax > maxLength) {
            maxLength = currentMax;
            // Calculate the exact starting index of this new longest palindrome
            start = i - (currentMax - 1) / 2;
            }
        }

        // Return the substring using its starting index and length
        return s.substr(start, maxLength);
    }

};