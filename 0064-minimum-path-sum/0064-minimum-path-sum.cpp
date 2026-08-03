class Solution {
       int helper(vector<vector<int>>&grid,int n,int m , vector<vector<int>>&dp){
          if(n < 0 || m < 0) return INT_MAX;
          if(n == 0 && m == 0) return grid[0][0];
          if(dp[n][m] != -1) return dp[n][m];
          int up = INT_MAX;
          int left = INT_MAX;
          if(n > 0) up = grid[n][m]+helper(grid,n-1,m,dp);
          if(m > 0) left = grid[n][m]+helper(grid,n,m-1,dp);
          return dp[n][m] = min(up,left);
       }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};