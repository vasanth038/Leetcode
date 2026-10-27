class Solution {
public:
    string helper(string s, int n) {

        if (n <= 1)
            return s;

        string c = "";
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                c += cnt + '0';
                c += s[i - 1];
                cnt = 1;
            }
        }
        c += cnt + '0';
        c += s.back();

        return helper(c, n - 1);
    }

    string countAndSay(int n) { return helper("1", n); }
};