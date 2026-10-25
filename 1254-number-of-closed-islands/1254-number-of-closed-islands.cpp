class Solution {
public:
    int n, m;
    void dfs(int r, int c, vector<vector<int>>& grid) {

        if (r < 0 || c < 0 || c >= m || r >= n || grid[r][c] == 1)
            return;

        grid[r][c] = 1;

        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            dfs(i, 0, grid);
            dfs(i, m - 1, grid);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, grid);
            dfs(n - 1, j, grid);
        }

        int count = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0){
                  count++;
                  dfs(i,j,grid);
                }
                    
            }
        }

        return count;
    }
};