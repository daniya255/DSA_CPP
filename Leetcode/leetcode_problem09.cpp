class Solution {
public:
    bool isPalindrome(int n) {
        if (n > INT_MAX || n < INT_MIN)
            return false;
        int orig = n;
        int ld;
        long rev = 0;
        while (n > 0) {
            ld = n % 10;
            rev = (rev * 10) + ld;
            n = n / 10;
        }
        if (rev == orig)
            return true;
        else
            return false;
    }
};