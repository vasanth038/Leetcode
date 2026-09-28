class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        vector<int> row(n, 1);
        vector<int> col(m, 1);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {

            if (row[i] == 1)
                continue;
            for (int j = 0; j < m; j++) {
                a[i][j] = 0;
            }
        }

        for (int j = 0; j < m; j++) {

            if (col[j] == 1)
                continue;
            for (int i = 0; i < n; i++) {
                a[i][j] = 0;
            }
        }
    }
};