class Solution {
public:
    int n, m;
    long long dfs(int r, int c, vector<vector<int>>& grid) {

        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0)
            return 0;

         long long  sum = grid[r][c];
        grid[r][c] = 0;
        sum += dfs(r - 1, c, grid);
        sum += dfs(r + 1, c, grid);
        sum += dfs(r, c + 1, grid);
        sum += dfs(r, c - 1, grid);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {

        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    cout<<sum<<"\n";
                    if (sum > 0 && sum % k == 0){
                         count++;
                    }
                        
                }
            }
        }

        return count;
    }
};