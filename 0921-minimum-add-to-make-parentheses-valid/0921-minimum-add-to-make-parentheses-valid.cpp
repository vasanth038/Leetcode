class Solution {
public:
    int minAddToMakeValid(string s) {

        int level = 0;
        int req = 0;

        for (auto ch : s) {

            level += ch == '(' ? +1 : -1;

            if (level < 0) {
                level = 0;
                req++;
            }
        }

        return req + level;
    }
};