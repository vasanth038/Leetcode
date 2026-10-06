class Solution {
public:
    string removeOuterParentheses(string s) {

        string t = "";

        int level = 0;

        for (auto ch : s) {

            if (ch == '(') {
                if (level > 0)
                    t += ch;
                level++;
            } else {
                level--;
                if (level > 0)
                    t += ch;
            }
        }

        return t;
    }
};