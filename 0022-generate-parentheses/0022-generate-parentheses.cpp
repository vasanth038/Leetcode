class Solution {

private:
    bool valid(string& s) {

        int level = 0;

        for (auto ch : s) {

            if (ch == '(')
                level++;
            else
                level--;

            if (level < 0)
                return false;
        }

        return level == 0 ? true : false;
    }

    void helper(string& s, int i, int m, vector<string>& ans) {

        if (i > m) {
            if (valid(s))
                ans.push_back(s);
            else
                return;
        }

        s.push_back('(');
        helper(s, i + 1, m, ans);
        s.pop_back();
        s.push_back(')');
        helper(s, i + 1, m, ans);
        s.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {

        int m = n * 2;
        string s = "";
        vector<string> ans;
        helper(s, 1, m, ans);

        return ans;
    }
};