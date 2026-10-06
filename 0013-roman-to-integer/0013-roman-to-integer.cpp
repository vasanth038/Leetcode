class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mpp = {
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = mpp[s[i]];
            if (i + 1 < n && mpp[s[i]] < mpp[s[i + 1]]) {
                cur = mpp[s[i + 1]] - mpp[s[i]];
                i++;
            }
            ans += cur;
        }

        return ans;
    }
};