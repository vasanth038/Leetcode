class Solution {
public:
    int helper(int i, int j, int cost, vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0)
            return 1e9;

         cost = cost ^ grid[i][j];
        if (i == 0 && j == 0)
            return cost;
        if (dp[i][j][cost] != -1)
            return dp[i][j][cost];
        int up = helper(i - 1, j, cost, grid, dp);
        int left = helper(i, j - 1, cost, grid, dp);
        return dp[i][j][cost] = min(up, left);
    }

    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return helper(n - 1, m - 1, 0, grid, dp);
    }
};