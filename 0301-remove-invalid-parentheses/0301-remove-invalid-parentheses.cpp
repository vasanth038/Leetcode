class Solution {

private:
    bool valid(string& cur) {
        int level = 0;
        for (auto ch : cur) {
            if (ch == '(')
                level++;
            else if (ch == ')')
                level--;

            if (level < 0) {
                return false;
            }
        }

        return level == 0;
    }
    void helper(string &s, int i, int k, set<string>& ans, string& cur) {
        int n = s.size();
        if (k < 0)
            return;
        if (i >= n) {
            if (k == 0 && valid(cur))
                ans.insert(cur);
            return;
        }
        if ((s[i] == ')' || s[i] == '(' ) )
            helper(s, i + 1, k - 1, ans, cur);
        cur.push_back(s[i]);
        helper(s, i + 1, k, ans, cur);
        cur.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int level = 0;
        int rem = 0;
        for (auto ch : s) {
            if (ch == '(')
                level++;
            else if (ch == ')')
                level--;

            if (level < 0) {
                level = 0;
                rem++;
            }
        }

        rem += level;
        set<string> st;
        string cur = "";
        helper(s, 0, rem, st, cur);
        return vector<string>(st.begin(),st.end());
    }
};