class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {

        if (a[1] == b[1])
            return a[0] < b[0];

        return a[1] < b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        sort(logs.begin(), logs.end(), comp);

        int m = queries.size();

        vector<vector<int>> qs(m, vector<int>(2));

        for (int i = 0; i < m; i++) {
            qs[i] = {i, queries[i]};
        }

        sort(qs.begin(), qs.end(), comp);

        vector<int> ans(m);
        vector<int> cnt(n + 1, 0);
        int busy = 0;
        int l = 0;
        int r = 0;
        for (int i = 0; i < m; i++) {

            int q = qs[i][1];
            int id = qs[i][0];
            while (r < logs.size() && logs[r][1] <= q) {
                busy += cnt[logs[r][0]]++ == 0;
                r++;
            }

            while (l < r && logs[l][1] < q - x) {
                busy -= --cnt[logs[l][0]] == 0;
                l++;
            }
            ans[id] = n - busy;
        }

        return ans;
    }
};