class Solution {
    int n, idx, maxLen;

private:
    void helper(string& s, int l, int r) {

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        if (maxLen < r - l - 1) {
            idx = l + 1;
            maxLen = r - l - 1;
        }
    }

public:
    string longestPalindrome(string s) {

        n = s.size();
        maxLen = 0;
        idx = 0;
        for (int i = 0; i < n; i++) {
            helper(s, i, i);
            helper(s, i, i + 1);
        }

        return s.substr(idx, maxLen);
    }
};