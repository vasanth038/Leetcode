#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();

        string ans = "";

        int i = n - 1;

        while (i >= 0) {

            while (i >= 0 && s[i] == ' ')
                i--;

            int j = i;

            while (j >= 0 && s[j] != ' ')
                j--;
            string cur = s.substr(j + 1, i - j);
            if (!ans.empty() && !cur.empty())
                ans += ' ';

            ans += cur;

            i = j;
        }

        return ans;
    }
};