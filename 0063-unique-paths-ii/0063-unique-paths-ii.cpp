class Solution {
    int helper(vector<vector<int>>&obstacleGrid,int n , int m,vector<vector<int>>&dp){
        if(m < 0 || n < 0) return 0;
        if(n == 0 && m == 0 &&  !obstacleGrid[n][m]) return 1;
        if(obstacleGrid[n][m] == 1) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int up = helper(obstacleGrid,n-1,m,dp);
        int left = helper(obstacleGrid,n,m-1,dp);
        return dp[n][m] = up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
         int m = obstacleGrid[0].size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
         n--;
         m--;
         return helper(obstacleGrid,n,m,dp);

    }
};