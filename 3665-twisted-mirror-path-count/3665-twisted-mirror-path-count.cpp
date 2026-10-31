class Solution {
public:
    const int mod = 1e9 + 7;
    int n, m;
    int helper(int i, int j, int dir, vector<vector<int>>& grid,
        vector<vector<vector<int>>>&dp) {

        if (i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        if (i == n-1 && j == m-1)
            return 1;
          if(dp[i][j][dir] != -1) return dp[i][j][dir];
        if (grid[i][j]) {
            if (dir) {
                return helper(i, j + 1, 0, grid,dp);
            } else
                return helper(i + 1, j, 1, grid,dp);
        }

        int right = helper(i, j + 1, 0, grid,dp);
        int down = helper(i + 1, j, 1, grid,dp) ;
         return dp[i][j][dir] = (right + down) % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        if(n == 1 && m == 1) return 1;
        int ans = 0;
        if(n > 1) ans = helper(0,1,0,grid,dp);
        if(m > 1) ans = (ans + helper(1,0,1,grid,dp) ) % mod;
      return ans;
    }
};